#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

void initBST(BST *A) {
	*A = NULL;
}

void insertElem(BST *A, int elem) {
	BST *trav;
	
	for(trav = A; *trav != NULL;) {
		trav = (elem < (*trav)->data) ? &(*trav)->left : &(*trav)->right;
	}
	
	if(*trav != NULL) {
		BST temp = (BST)malloc(sizeof(struct node));
		if(temp != NULL) {
			temp->data = elem;
			temp->left = NULL;
			temp->right = NULL;
			*trav = temp;
		}
	}
}

void deleteElem(BST *A, int elem) {
	
}

bool isMember(BST *A, int elem) {
	
}

void displayBST(BST *A) {
	
}

void visualizeBST(BST *A) {
	
}

int min(BST *A) { // this function returns the minimum value of the tree

}

int max(BST *A) { // this function returns the maximum value of the tree

}

void preorder(BST A) { // NLR (node, left right)
	printf("Preorder of the BST: { ");
	if(A != NULL) {
		printf("%d ", A->data);
		preorder(A->left);
		preorder(A->right);
	}
	printf("}");
}

void inorder(BST A) { // LNR (left, node, right)
	printf("Inorder of the BST: { ");
	if(A != NULL) {
		inorder(A->left);
		printf("%d ", A->data);
		inorder(A->right);
	}
	printf("}");
}

void postorder(BST A) { // LRN (left, right, node)
	if(A != NULL) {
		postorder(A->left);
		postorder(A->right);
		printf("%d ", A->data);
	}
}
