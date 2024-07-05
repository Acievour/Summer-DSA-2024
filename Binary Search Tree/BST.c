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

void addElem(NodePtr *A, Product elem) { // recursive

}

void deleteElem(NodePtr *A, Product elem) { // non recursive
	NodePtr *trav1, *trav2, temp;
	
	for(trav1 = A; *trav1 != NULL && ((*trav1)->item.prodName, elem.prodName) != 0;) {
		if(strcmp(elem.prodName, (*trav1)->item.prodName) < 0) {
			trav1 = &(*trav1)->left;
		} else {
			trav1 = &(*trav1)->right;
		}
	}
	
	if(*trav1 != NULL) {
		temp = (NodePtr)malloc(sizeof(NodeType));
		if(temp != NULL) {
			if((*trav1)->left == NULL) {
				temp = *trav1;
				*trav1 = temp->right;
				free(temp);
			} else if((*trav1)->right == NULL) {
				temp = *trav1;
				*trav1 = temp->left;
				free(temp);
			} else {
				for(trav2 = &(*trav1)->right; (*trav2)->left != NULL; trav2 = &(*trav2)->left) {}
				
				temp = *trav2;
				*trav2 = temp->right;
				(*trav1)->item = temp->item;
				free(temp);
			}
		}
	}
}

void removeElem(NodePtr *A, Product elem) { // recursive

}

bool isMember(NodePtr A, Product elem) {
	
}

char *min(NodePtr A) { // this function returns the minimum value of the tree
	NodePtr trav;
	for(trav = A; trav != NULL; trav = trav->left) {}
	return trav->item.prodName;
}

char *max(NodePtr A) { // this function returns the maximum value of the tree
	NodePtr trav;
	for(trav = A; trav != NULL; trav = trav->right) {}
	return trav->item.prodName;
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
