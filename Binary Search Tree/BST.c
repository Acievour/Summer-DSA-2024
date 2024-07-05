#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"

void initBST(NodePtr *A) {
	*A = NULL;
}

void insertElem(NodePtr *A, Product elem) { // non recursive
	NodePtr *trav;
	
	for(trav = A; *trav != NULL;) {
		if(strcmp(elem.prodName, (*trav)->item.prodName) < 0) {
			trav = &(*trav)->left;
		} else {
			trav = &(*trav)->right;
		}
	}
	
	if(*trav == NULL) {
		NodePtr temp = (NodePtr)malloc(sizeof(NodeType));
		if(temp != NULL) {
			temp->item = elem;
			temp->left = NULL;
			temp->right = NULL;
			*trav = temp;
		}
	}
}

void deleteElem(NodePtr *A, Product elem) { // non recursive
	
}

bool isMember(NodePtr A, Product elem) {
	
}

int min(NodePtr A) { // this function returns the minimum value of the tree

}

int max(NodePtr A) { // this function returns the maximum value of the tree

}

void displayBST(NodePtr A) {
	
}

void visualizeBST(NodePtr A) {
	
}

void preorder(NodePtr A) { // NLR (node, left right)
	if(A != NULL) {
		printf("%s ", A->item.prodName);
		preorder(A->left);
		preorder(A->right);
	}
}

void inorder(NodePtr A) { // LNR (left, node, right)
	if(A != NULL) {
		inorder(A->left);
		printf("%s ", A->item.prodName);
		inorder(A->right);
	}
}

void postorder(NodePtr A) { // LRN (left, right, node)
	if(A != NULL) {
		postorder(A->left);
		postorder(A->right);
		printf("%s ", A->item.prodName);
	}
}
