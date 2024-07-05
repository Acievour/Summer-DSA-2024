#ifndef BST_H
#define BST_H

#include <stdbool.h>

typedef struct {
	int day, month, year;
} Date;

typedef struct {
	char prodName[20];
	float prodPrice;
	int prodQty;
	Date expDate;
} Product;

typedef struct node {
	Product item;
	struct node *left;
	struct node *right;
} NodeType, *NodePtr;

void initBST(NodePtr *A);

void insertElem(NodePtr *A, Product elem); // non recursive
void deleteElem(NodePtr *A, Product elem); // non recursive
bool isMember(NodePtr A, Product elem);

int min(NodePtr A); // this function returns the minimum value of the tree
int max(NodePtr A); // this function returns the maximum value of the tree

void displayBST(NodePtr A); // breadth first search using queue
void visualizeBST(NodePtr A);

void preorder(NodePtr A); // NLR (node, left right)
void inorder(NodePtr A); // LNR (left, node, right)
void postorder(NodePtr A); // LRN (left, right, node)

#endif
