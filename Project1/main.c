//Owen Davis Prog72370 Assignment 2
#include "List.h"
#include <time.h>
#define data "abcdefghijklmnopqrstuvwxyz"

int main(void) {
	srand(time(NULL));
	//create head
	TREE* head = createNode(data[rand() % (26)]);

	//fill tree
	int numNodes = (rand() % (20 - 11 + 1)) + 11;
	for (int i = 0; i < numNodes; i++) {
		TREE* newNode = createNode(data[rand() % (26)]);
		tInsert(&head, newNode);
	}
	tPrint(head);
	printf("\nThere are %d nodes in the tree\n", tCount(head));
	printf("There are %d levels in the tree\n", tLevels(head));

	if (tSearch(head, 'x') != NULL)
		printf("Letter x found (Search test)");
	else printf("Letter x not found (Search test)");
	
	tFree(head);

	return 0;
}