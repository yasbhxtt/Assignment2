//Yash B - Binary Search Tree - Assignment 2
#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTree.h"


Node* createNode(char data) { // function to create a new node
    Node* newNode = (Node*)malloc(sizeof(Node)); //allocate memory for new node
    if (!newNode) { //memory allocation check to see if it was successfull
        printf("Memory allocation failed\n");   //print if fails
        exit(1);
    }
    newNode->data = data;   //assign data to new node
    newNode->left = newNode->right = NULL;  //initialize left/right children as NULL
    return newNode;
}


Node* insert(Node* root, char data) {   // insert a node into the binary search tree
    if (root == NULL) { // if tree is empty create a new node
        return createNode(data); 
    }
    if (data < root->data) {    //insert in left subtree if the data is smaller
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);    //insert in right subtree if data is larger
    }
    return root;
}


Node* search(Node* root, char data) {   // function to search for a node in thebinary search tree
    if (root == NULL || root->data == data) {   //if found or NULL, return root
        return root;
    }
    if (data < root->data) {    //search data in left subtree
        return search(root->left, data);
    }
    else {
        return search(root->right, data);   //search data in right subtree
    }
}


int countNodes(Node* root) {    //function to count the number of nodes in the tree
    if (root == NULL) { //if tree is NULL/empty return 0
        return 0;
    }   //count current node /left/right
    return 1 + countNodes(root->left) + countNodes(root->right);
}


int treeHeight(Node* root) {    //function to determine height of tree
    if (root == NULL) { //if the tree is empty return -1
        return -1;
    }
    int leftHeight = treeHeight(root->left);    //height of left subtree
    int rightHeight = treeHeight(root->right);  //height of right subtree
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;   //return the max height + 1
}

void inorderTraversal(Node* root) { //function to print tree into a sorted order/inorder traversal
    if (root != NULL) { 
        inorderTraversal(root->left);   //visit left subtree
        printf("%c ", root->data);  //print the current nodes data
        inorderTraversal(root->right);  //visit righ tree
    }
}

void freeTree(Node* root) { //function to free the memory allocated for tree
    if (root != NULL) {
        freeTree(root->left);   //free the left subtree
        freeTree(root->right);  //free the right subtree
        free(root); //free node
    }
}
