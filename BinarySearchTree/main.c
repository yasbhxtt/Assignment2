//Yash B - Binary Search Tree - Assignment 2
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binarySearchTree.h"

int main() {
    srand(time(NULL));  // seed random number generator

    int numChars = rand() % 10 + 11; //generate number between 11 and 20
    char* insertedChars = (char*)malloc(numChars * sizeof(char)); // allocate memory for storing the characters inserted

    if (insertedChars == NULL) {    //if statement to check if memory allocation was successful
        printf("Memory allocation failed\n");   //print for failed memory allocation
        return 1;
    }

    Node* root = NULL;  //initialization of root for tree

    printf("Inserting characters: ");   //insert characters
    for (int i = 0; i < numChars; i++) {
        char randomChar = 'a' + rand() % 26; //generate random character from a-z (26 letters)
        insertedChars[i] = randomChar; //store character into array
        root = insert(root, randomChar);    //insert the character into tree
        printf("%c ", randomChar);  //print inserted character
    }


    printf("\n\nSorted order: ");   //print sorted order
    inorderTraversal(root); //inorder traversal to print sorted characters
    printf("\n");

    printf("Number of nodes: %d\n", countNodes(root));  //print number of total nodes
    printf("Tree height: %d\n", treeHeight(root));  // print height of tree

    free(insertedChars); //free allocated memory
    freeTree(root); //free the tree memory
    return 0;
}

