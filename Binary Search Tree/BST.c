#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"

void initBST(NodePtr *A) {
	*A = NULL;
}

QNode* createQNode(NodePtr data) {
	QNode *newNode = (QNode*)malloc(sizeof(QNode));
    if(newNode != NULL) {
        newNode->data = data;
    	newNode->next = NULL;
    	return newNode;
    }
}

Queue* createQueue() {
	Queue *queue = (Queue*)malloc(sizeof(Queue));
    if(queue != NULL) {
        queue->front = NULL;
    	queue->rear = NULL;
    	return queue;
	}
}

int isEmpty(Queue *queue) {
	return(queue->front == NULL);
}

void enqueue(Queue *queue, NodePtr data) {
	QNode *newNode = createQNode(data);
    if(queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

NodePtr dequeue(Queue *queue) {
	if(!isEmpty(queue)) {
        QNode *temp = queue->front;
	    NodePtr data = temp->data;
	    queue->front = queue->front->next;
	    if(queue->front == NULL) {
	        queue->rear = NULL;
	    }
	    free(temp);
	    return data;
    }
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
	if (*A != NULL) {
		NodePtr parent = NULL;
	    NodePtr current = *A;
	
	    while (current != NULL) {
	        if (strcmp(elem.prodName, current->item.prodName) == 0) {
	            if (current->left == NULL && current->right == NULL) {
	                if (parent == NULL) {
	                    *A = NULL;
	                } else if (parent->left == current) {
	                    parent->left = NULL;
	                } else {
	                    parent->right = NULL;
	                }
	                free(current);
	                return;
	            } else if (current->left == NULL) {
	                if (parent == NULL) {
	                    *A = current->right;
	                } else if (parent->left == current) {
	                    parent->left = current->right;
	                } else {
	                    parent->right = current->right;
	                }
	                free(current);
	                return;
	            } else if (current->right == NULL) {
	                if (parent == NULL) {
	                    *A = current->left;
	                } else if (parent->left == current) {
	                    parent->left = current->left;
	                } else {
	                    parent->right = current->left;
	                }
	                free(current);
	                return;
	            } else {
	                NodePtr successor = min(current->right);
	
	                strcpy(current->item.prodName, successor->item.prodName);
	                current->item.prodPrice = successor->item.prodPrice;
	                current->item.prodQty = successor->item.prodQty;
	                current->item.expDate.day = successor->item.expDate.day;
	                current->item.expDate.month = successor->item.expDate.month;
	                current->item.expDate.year = successor->item.expDate.year;
	
	                deleteElem(&(current->right), successor->item);
	                return;
	            }
	        } else if (strcmp(elem.prodName, current->item.prodName) < 0) {
	            parent = current;
	            current = current->left;
	        } else {
	            parent = current;
	            current = current->right;
	        }
	    }
	}
}

void removeElem(NodePtr *A, Product elem) { // recursive

}

int isMember(NodePtr A, Product elem) {
	while (A != NULL) {
        int cmp = strcmp(elem.prodName, A->item.prodName);
        if (cmp == 0) {
            return 1;
        } else if (cmp < 0) {
            A = A->left;
        } else {
            A = A->right;
        }
    }
    return 0;
}

NodePtr min(NodePtr A) { // this function returns the minimum value of the tree
	NodePtr trav;
	for(trav = A; trav != NULL; trav = trav->left) {}
	return trav;
}

NodePtr max(NodePtr A) { // this function returns the maximum value of the tree
	NodePtr trav;
	for(trav = A; trav != NULL; trav = trav->right) {}
	return trav;
}

void displayBST(NodePtr A) {
	if (A != NULL) {
        Queue *queue = createQueue();
   		enqueue(queue, A);
	
	    while (!isEmpty(queue)) {
	        NodePtr current = dequeue(queue);
	        printf("%s ", current->item.prodName);
	
	        if (current->left != NULL) {
	            enqueue(queue, current->left);
	        }
	        if (current->right != NULL) {
	            enqueue(queue, current->right);
	        }
	    }
    	printf("\n");
    }
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
