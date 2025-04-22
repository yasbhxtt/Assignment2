//Yash B - Binary Search Tree - Assignment 2
#include <stdio.h>
#pragma once
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H



typedef struct Node {   //definition of node struct

    char data;  //char data stored in node
    struct Node* left;  //pointer to left child
    struct Node* right; //pointer to right child

} Node;

//function declarations
Node* insert(Node* root, char data);    //insert function for new character into tree
Node* search(Node* root, char data);    //search function to search for character in tree
int countNodes(Node* root);             //counter for total # of nodes
int treeHeight(Node* root);             //height calculator of bst
void inorderTraversal(Node* root);      //perform inorder traversal to print elements in order
void freeTree(Node* root);              //free allocated memory

#endif
