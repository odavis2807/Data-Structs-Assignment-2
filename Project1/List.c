//Owen Davis Prog72370 Assignment 2
#include "List.h"

//returns Tree node with allocated memory
TREE* createNode(char data) {
	TREE* newNode;
	newNode = (TREE*)malloc(sizeof(TREE));
	newNode->data = data;
	newNode->lNode = NULL;
	newNode->rNode = NULL;
	return newNode;
}
//Recursively inserts a new node
void tInsert(TREE** head, TREE* input) {
	if (input->data < (*head)->data) {
		if ((*head)->lNode == NULL) {
			(*head)->lNode = input;
			return;
		}
		tInsert(&((*head)->lNode), input);
	}

	if (input->data > (*head)->data) {
		if ((*head)->rNode == NULL) {
			(*head)->rNode = input;
			return;
		}
		tInsert(&((*head)->rNode), input);
	}

}
//Returns a node with inputted data if it exists in the tree
TREE* tSearch(TREE* head, char data) {
	if (head == NULL)
		return NULL;
	if (head->data == data)
		return head;
	if (data > head->data)
		return tSearch(head->rNode, data);
	if (data < head->data)
		return tSearch(head->lNode, data);
}
//counts total nodes in a tree
int tCount(TREE* head) {
	if (head == NULL)
		return 0;
	return (tCount(head->lNode) + tCount(head->rNode) + 1);
}
//counts total levels in the tree
int tLevels(TREE* head) {
	int left, right;
	if (head == NULL)
		return (-1);
	left = tLevels(head->lNode);
	right = tLevels(head->rNode);
	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}
//prints tree in alphabetical order
void tPrint(TREE* head) {
	if (head == NULL)
		return;
	tPrint(head->lNode);
	printf("%c", head->data);
	tPrint(head->rNode);
	return;
}
//frees tree in postorder
void tFree(TREE* head) {
	tFree(head->lNode);
	tFree(head->rNode);
	free(head);
	return;
}