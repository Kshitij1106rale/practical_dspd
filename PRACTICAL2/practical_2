/*
Design, Develop and Implement a menu driven Program in C for the following operations on STACK of Integers (Array Implementation of Stack with maximum size MAX)
a. Push an Element on to Stack
b. Pop an Element from Stack
c. Demonstrate how Stack can be used to check Palindrome
d. Demonstrate Overflow and Underflow situations on Stack
e. Display the status of Stack
f. Exit
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

int stack_arr[MAX];
int top = -1;

void push(int item) {
    if (top == MAX - 1) {
        printf("STACK OVERFLOW. Cannot push %d.\n", item);
        return;
    }
    stack_arr[++top] = item;
    printf("Pushed %d onto stack.\n", item);
}

void pop() {
    int item;
    if (top == -1) {
        printf("STACK UNDERFLOW. Cannot pop.\n");
        return;
    }
    item = stack_arr[top--];
    printf("Popped %d from stack.\n", item);
}

void checkPalindrome() {
    char str[100];
    char stack_local[100];
    int top_local = -1;
    int i, len;
    int is_palindrome = 1;

    printf("Enter a string to check for palindrome: ");
    scanf("%s", str);
    len = strlen(str);

    for (i = 0; i < len; i++) {
        stack_local[++top_local] = str[i];
    }

    for (i = 0; i < len; i++) {
        if (stack_local[top_local--] != str[i]) {
            is_palindrome = 0;
            break;
        }
    }

    if (is_palindrome) {
        printf("'%s' is a palindrome.\n", str);
    } else {
        printf("'%s' is not a palindrome.\n", str);
    }
}

void demonstrateOverflow() {
    int i;
    printf("\n--- Demonstrating Overflow ---\n");
    top = -1;
    printf("Filling stack (MAX=%d)...\n", MAX);
    for (i = 1; i < MAX; i++) {
        stack_arr[++top] = i ;
        printf("Pushed %d\n", i);
    }
    
    printf("Stack is now full. Attempting to push one more...\n");
    if (top == MAX - 1) {
        printf("STACK OVERFLOW situation.\n");
    } else {
        stack_arr[++top] = 99;
    }
    top = -1;
    printf("Stack reset for normal use.\n");
}

void demonstrateUnderflow() {
    printf("\n--- Demonstrating Underflow ---\n");
    top = -1;
    printf("Stack is empty. Attempting to pop...\n");
    if (top == -1) {
        printf("STACK UNDERFLOW situation.\n");
    } else {
        int item = stack_arr[top--];
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack status (top to bottom):\n");
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack_arr[i]);
    }
}

int main() {
    int choice, item;

    while (1) {
        printf("\n--- STACK MENU (MAX = %d) ---\n", MAX);
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check Palindrome\n");
        printf("4. Demonstrate Overflow and Underflow\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                demonstrateOverflow();
                demonstrateUnderflow();
                break;
            case 5:
                display();
                break;
            case 6:
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

--- STACK MENU (MAX = 5) ---
1. Push
2. Pop
3. Check Palindrome
4. Demonstrate Overflow and Underflow
5. Display Stack
6. Exit
Enter your choice: 1
Enter element to push: 3
Pushed 3 onto stack.

--- STACK MENU (MAX = 5) ---
Enter your choice: 1
Enter element to push: 2
Pushed 2 onto stack.

--- STACK MENU (MAX = 5) ---
Enter your choice: 5
Stack status (top to bottom):
2
3

--- STACK MENU (MAX = 5) ---
...
Enter your choice: 2
Popped 2 from stack.

--- STACK MENU (MAX = 5) ---
Enter your choice: 5
Stack status (top to bottom):
3

--- STACK MENU (MAX = 5) ---
Enter your choice: 3
Enter a string to check for palindrome: madam
'madam' is a palindrome.

--- STACK MENU (MAX = 5) ---
Enter your choice: 3
Enter a string to check for palindrome: kshitij
'kshitij' is not a palindrome.

--- STACK MENU (MAX = 5) ---
Enter your choice: 4

--- Demonstrating Overflow ---
Filling stack (MAX=5)
Pushed 1
Pushed 2
Pushed 3
Pushed 3
Pushed 4
Stack is now full. Attempting to push one more...
STACK OVERFLOW situation.
Stack reset for normal use.

--- Demonstrating Underflow ---
Stack is empty. Attempting to pop...
STACK UNDERFLOW situation.

--- STACK MENU (MAX = 5) ---
Enter your choice: 5
Stack is empty.

--- STACK MENU (MAX = 5) ---
Enter your choice: 6
Exiting program.
*/
