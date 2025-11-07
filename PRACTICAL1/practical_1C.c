/* Write a program which creates a structure Student which must have the attribute Avg Marks with 3 more attributes sort the list of the student in descending order using Bubble sort. */


#include <stdio.h>
#include <string.h>


struct Student {
    int rollNo;
    char name[50];
    int age;
    float avgMarks;
};


void bubbleSort(struct Student students[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].avgMarks < students[j + 1].avgMarks) {
                // Swap
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}


void display(struct Student students[], int n) {
    printf("\nSorted Student List (Descending by Avg Marks):\n");
    for (int i = 0; i < n; i++) {
        printf("Roll No: %d, Name: %s, Age: %d, Avg Marks: %.2f\n",
               students[i].rollNo, students[i].name, students[i].age, students[i].avgMarks);
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];

   
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name); 
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Average Marks: ");
        scanf("%f", &students[i].avgMarks);
    }

  
    bubbleSort(students, n);
    display(students, n);

    return 0;
}

/*OUTPUT:
Enter number of students: 3

Enter details for student 1:
Roll No: 101
Name: kshitij
Age: 20
Average Marks: 78.5

Enter details for student 2:
Roll No: 102
Name: rahul
Age: 21
Average Marks: 85.0

Enter details for student 3:
Roll No: 103
Name: aditya
Age: 19
Average Marks: 67.25

Sorted Student List (Descending by Avg Marks):
Roll No: 102, Name: rahul, Age: 21, Avg Marks: 85.00
Roll No: 101, Name: kshitij, Age: 20, Avg Marks: 78.50
Roll No: 103, Name: aditya, Age: 19, Avg Marks: 67.25

*/