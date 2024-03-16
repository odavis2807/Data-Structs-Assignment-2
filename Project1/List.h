//Owen Davis Prog72370 Assignment 2
#pragma once
#include <stdio.h>
#include <stdlib.h>

//Tree node struct
typedef struct Tree {
	char data;
	struct Tree* lNode;
	struct Tree* rNode;
}TREE;

TREE* createNode(char data);
void tInsert(TREE** head, TREE* input);
TREE* tSearch(TREE* head, char data);
int tCount(TREE* head);
int tLevels(TREE* head);
void tPrint(TREE* head);
void tFree(TREE* head);