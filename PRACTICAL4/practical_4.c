/*
This C program creates a linked list to store integer elements. It
prompts the user to enter elements and add them to the list until the user
enters 0. It then traverses the list and prints each element and
"=>" until reaching the null pointer. Finally, it displays the
number of nodes in the list.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* new_node = NULL;
    int data;
    int count = 0;

    printf("Enter elements (enter 0 to stop):\n");

    while (1) {
        printf("Enter element: ");
        scanf("%d", &data);

        if (data == 0) {
            break;
        }

        new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = NULL;
        count++;

        if (head == NULL) {
            head = new_node;
            temp = new_node;
        } else {
            temp->next = new_node;
            temp = new_node;
        }
    }

    printf("\nThe linked list is:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d => ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Number of nodes in the list: %d\n", count);

    return 0;
}

/*
Sample Output:
Enter elements (enter 0 to stop):
Enter element: 6
Enter element: 40
Enter element: 1
Enter element: 56
Enter element: 0

The linked list is:
6 => 40 => 1 => 56 => NULL
Number of nodes in the list: 4
*/
