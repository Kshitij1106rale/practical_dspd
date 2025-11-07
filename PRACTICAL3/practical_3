/*
Design, Develop and Implement a menu driven Program in C for the
following operations on QUEUE of Characters (Array Implementation of Queue with
maximum size MAX)
a. Insert an Element on to QUEUE
b. Delete an Element from QUEUE
c. Demonstrate Overflow and Underflow situations on QUEUE
d. Display the status of QUEUE
e. Exit
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

char queue_arr[MAX];
int front = -1;
int rear = -1;

void enqueue(char item) {
    if ((rear + 1) % MAX == front) {
        printf("QUEUE OVERFLOW. Cannot insert %c.\n", item);
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue_arr[rear] = item;
    printf("Inserted %c into queue.\n", item);
}

void dequeue() {
    char item;
    if (front == -1) {
        printf("QUEUE UNDERFLOW. Cannot delete.\n");
        return;
    }
    item = queue_arr[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    printf("Deleted %c from queue.\n", item);
}

void demonstrateOverflow() {
     printf("\n--- Demonstrating Overflow ---\n");
    front = rear = -1;
    enqueue('R');
    enqueue('A');
    enqueue('M');
    enqueue('A');
    enqueue('N');

    printf("Queue is now full. Attempting to insert one more...\n");
    enqueue('I');
    
    front = -1;
    rear = -1;
    printf("Queue reset for normal use.\n");
}

void demonstrateUnderflow() {
    printf("\n--- Demonstrating Underflow ---\n");
    front = -1;
    rear = -1;
    printf("Queue is empty. Attempting to delete...\n");
    dequeue();
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue status (Front to Rear):\n");
    
    if (rear >= front) {
        for (i = front; i <= rear; i++) {
            printf("%c ", queue_arr[i]);
        }
    } else {
        for (i = front; i < MAX; i++) {
            printf("%c ", queue_arr[i]);
        }
        for (i = 0; i <= rear; i++) {
            printf("%c ", queue_arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice;
    char item;

    while (1) {
        printf("\n--- QUEUE MENU (MAX = %d) ---\n", MAX);
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Demonstrate Overflow and Underflow\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                demonstrateOverflow();
                demonstrateUnderflow();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

/*
Sample Output:

--- QUEUE MENU (MAX = 5) ---
1. Insert (Enqueue)
2. Delete (Dequeue)
3. Demonstrate Overflow and Underflow
4. Display Queue
5. Exit
Enter your choice: 1
Enter character to insert: k
Inserted k into queue.

--- QUEUE MENU (MAX = 5) ---
Enter your choice: 1
Enter character to insert: s
Inserted s into queue.

--- QUEUE MENU (MAX = 5) ---
Enter your choice: 4
Queue status (Front to Rear):
k s

--- QUEUE MENU (MAX = 5) ---
Enter your choice: 2
Deleted k from queue.

--- QUEUE MENU (MAX = 5) ---
Enter your choice: 4
Queue status (Front to Rear):
s

--- QUEUE MENU (MAX = 5) ---
Enter your choice: 3

--- Demonstrating Overflow ---
Filling queue (MAX=5)...
Inserted R into queue.
Inserted A into queue.
Inserted M into queue.
Inserted A into queue.
Inserted N into queue.
Queue is now full. Attempting to insert one more...
QUEUE OVERFLOW. Cannot insert I.
Queue reset for normal use.

--- Demonstrating Underflow ---
Queue is empty. Attempting to delete...
QUEUE UNDERFLOW. Cannot delete.

--- QUEUE MENU (MAX = 5) ---
Enter your choice: 4
Queue is empty.

--- QUEUE MENU (MAX = 5) ---
Enter your choice: 5
Exiting program.
*/
