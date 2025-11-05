from ultralytics import YOLO
import cv2
import os
from datetime import datetime
from twilio.rest import Client

# Load YOLOv8 pre-trained model
model = YOLO("yolov8n.pt")

# Twilio Alert Setup (SMS / CALL)
account_sid = "YOUR_TWILIO_SID"
auth_token = "YOUR_TWILIO_TOKEN"
client = Client(account_sid, auth_token)

def send_alert(message):
    client.messages.create(
        body=message,
        from_="+1234567890",  # Twilio number
        to="+919xxxxxxxxx"    # Your phone number
    )

# Create folders if not exists
os.makedirs("emergency_clips", exist_ok=True)
os.makedirs("normal_clips", exist_ok=True)

cap = cv2.VideoCapture("input_videos/sample.mp4")

fourcc = cv2.VideoWriter_fourcc(*"mp4v")

def new_output(is_emergency):
    filename = datetime.now().strftime("%Y-%m-%d_%H-%M-%S") + ".mp4"
    folder = "emergency_clips" if is_emergency else "normal_clips"
    return cv2.VideoWriter(f"{folder}/{filename}", fourcc, 20.0, (640, 480))

recording_emergency = new_output(True)
recording_normal = new_output(False)

emergency_detected = False
frame_counter = 0

while True:
    ret, frame = cap.read()
    if not ret:
        break

    frame_counter += 1
    results = model(frame, verbose=False)

    emergency_frame = False

    for result in results:
        for box in result.boxes:
            cls = int(box.cls)
            label = model.names[cls]

            # Simple rules (Prototype):
            # Fall → accident, Fight → emergency, Car Motorbike collision → emergency
            if label in ["person"] and box.xyxy[0][3] - box.xyxy[0][1] > 350:
                emergency_frame = True  # unusual posture (fall / collapse)

            if label in ["car", "motorbike", "truck"] and box.conf > 0.7:
                # If vehicle area overlaps → accident possibility
                emergency_frame = True

    frame = cv2.resize(frame, (640, 480))

    if emergency_frame:
        emergency_detected = True
        recording_emergency.write(frame)
    else:
        recording_normal.write(frame)

    cv2.imshow("Video Monitoring", frame)

    # Send alert once when accident is detected
    if emergency_detected:
        send_alert("⚠ Accident / Emergency Detected! Immediate assistance required.")
        emergency_detected = False  # reset

    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

cap.release()
recording_emergency.release()
recording_normal.release()
cv2.destroyAllWindows()
