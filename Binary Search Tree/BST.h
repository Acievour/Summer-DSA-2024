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

typedef struct qnode {
	NodePtr data;
	struct qnode *next;
} QNode;

typedef struct {
	QNode *front;
	QNode *rear;
} Queue;

void initBST(NodePtr *A);

QNode* createQNode(NodePtr data);
Queue* createQueue();
int isEmpty(Queue *queue);
void enqueue(Queue *queue, NodePtr data);
NodePtr dequeue(Queue *queue);

void insertElem(NodePtr *A, Product elem); // non recursive
void addElem(NodePtr *A, Product elem); // recursive
void deleteElem(NodePtr *A, Product elem); // non recursive
void removeElem(NodePtr *A, Product elem); // recursive
int isMember(NodePtr A, Product elem);

NodePtr min(NodePtr A); // this function returns the minimum value of the tree
NodePtr max(NodePtr A); // this function returns the maximum value of the tree

void displayBST(NodePtr A); // breadth first search using queue
void visualizeBST(NodePtr A);

void preorder(NodePtr A); // NLR (node, left right)
void inorder(NodePtr A); // LNR (left, node, right)
void postorder(NodePtr A); // LRN (left, right, node)

#endif
