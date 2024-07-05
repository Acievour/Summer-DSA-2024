#ifndef BST_H
#define BST_H

#include <stdbool.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} *BST;

void initBST(BST *A);

void insertElem(BST *A, int elem);
void deleteElem(BST *A, int elem);
bool isMember(BST *A, int elem);

void displayBST(BST *A);
void visualizeBST(BST *A);

int min(BST *A); // this function returns the minimum value of the tree
int max(BST *A); // this function returns the maximum value of the tree

void preorder(BST A); // NLR (node, left right)
void inorder(BST A); // LNR (left, node, right)
void postorder(BST A); // LRN (left, right, node)

#endif
