/*
Write a program to insert Number of Nodes in
the Binary Tree and Traverse in Inorder , Preorder and Post Order and  Search an element in Binary Tree(Display NULL
if not found, If found Display Found)
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

void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
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


int main() {
    struct Node* root = NULL;
    struct Node* result = NULL;
    int n, i, data, key;

    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("\nInorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    printf("\nEnter an element to search: ");
    scanf("%d", &key);

    result = search(root, key);

    if (result != NULL) {
        printf("Found\n");
    } else {
        printf("NULL (Not Found)\n");
    }
    
    printf("\nEnter another element to search: ");
    scanf("%d", &key);
    
    result = search(root, key);
    
    if (result != NULL) {
        printf("Found\n");
    } else {
        printf("NULL (Not Found)\n");
    }

    return 0;
}

/*
Sample Output:
Enter the number of nodes to insert: 6
Enter 6 numbers:
42
25
45
20
40
58

Inorder traversal: 20 25 40 42 45 58
Preorder traversal: 42 25 20 40 45 58
Postorder traversal: 20 40 25 58 45 42

Enter an element to search: 40
Found

Enter another element to search: 66
NULL (Not Found)
*/
