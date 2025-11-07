/*
Implement Binary search tree(BST) with
following Menu operations.
1.         Search an element in BST(Display NULL if not found, If found Display Found)
2.         Insert an element in BST
3.         Delete leaf element in BST
4.         Exit
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

struct Node* deleteLeaf(struct Node* root, int key) {
    struct Node* parent = NULL;
    struct Node* current = root;

    while (current != NULL && current->data != key) {
        parent = current;
        if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current == NULL) {
        printf("Element %d not found in the BST.\n", key);
        return root;
    }

    if (current->left != NULL || current->right != NULL) {
        printf("Element %d is not a leaf node. Cannot delete.\n", key);
        return root;
    }

    printf("Deleting leaf node %d.\n", key);
    
    if (parent == NULL) {
        free(current);
        return NULL;
    }

    if (parent->left == current) {
        parent->left = NULL;
    } else {
        parent->right = NULL;
    }
    
    free(current);
    return root;
}

void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


int main() {
    struct Node* root = NULL;
    struct Node* result = NULL;
    int choice, data;

    while (1) {
        printf("\n--- BINARY SEARCH TREE MENU ---\n");
        printf("1. Insert Element\n");
        printf("2. Search Element\n");
        printf("3. Delete Leaf Element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Inserted %d. Current tree (Inorder): ", data);
                inorder(root);
                printf("\n");
                break;
            case 2:
                printf("Enter element to search: ");
                scanf("%d", &data);
                result = search(root, data);
                if (result != NULL) {
                    printf("Found\n");
                } else {
                    printf("NULL (Not Found)\n");
                }
                break;
            case 3:
                printf("Enter leaf element to delete: ");
                scanf("%d", &data);
                root = deleteLeaf(root, data);
                printf("Current tree (Inorder): ");
                inorder(root);
                printf("\n");
                break;
            case 4:
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

--- BINARY SEARCH TREE MENU ---
1. Insert Element
2. Search Element
3. Delete Leaf Element
4. Exit
Enter your choice: 1
Enter element to insert: 5
Inserted 5. Current tree (Inorder): 5

--- BINARY SEARCH TREE MENU ---
Enter your choice: 1
Enter element to insert: 3
Inserted 3. Current tree (Inorder): 3 5

--- BINARY SEARCH TREE MENU ---
Enter your choice: 1
Enter element to insert: 7
Inserted 7. Current tree (Inorder): 3 5 7

--- BINARY SEARCH TREE MENU ---
Enter your choice: 1
Enter element to insert: 2
Inserted 2. Current tree (Inorder): 2 3 5 7

--- BINARY SEARCH TREE MENU ---
Enter your choice: 1
Enter element to insert: 4
Inserted 4. Current tree (Inorder): 2 3 4 5 7

--- BINARY SEARCH TREE MENU ---
Enter your choice: 2
Enter element to search: 4
Found

--- BINARY SEARCH TREE MENU ---
Enter your choice: 2
Enter element to search: 10
NULL (Not Found)

--- BINARY SEARCH TREE MENU ---
Enter your choice: 3
Enter leaf element to delete: 3
Element 3 is not a leaf node. Cannot delete.
Current tree (Inorder): 2 3 4 5 7

--- BINARY SEARCH TREE MENU ---
Enter your choice: 3
Enter leaf element to delete: 2
Deleting leaf node 2.
Current tree (Inorder): 3 4 5 7

--- BINARY SEARCH TREE MENU ---
Enter your choice: 4
Exiting program.
*/