#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ND
{
	int data;
	struct ND *lptr;
	struct ND *rptr;
} ND;

typedef struct
{
	int count;
	ND *head;
} DLL;

ND *createNode();
DLL *createDll();

void printList(DLL *list);
void insert_pos(DLL *dll, int pos, int ele);
void delete_pos(DLL *dll, int pos);
void delete_key(DLL *dll, int ele);
void search_key(DLL *dll, int ele);
void order_inst(DLL *dll, int ele);
void rev_list(DLL *dll);

DLL *copy_list(DLL *source);

int main()
{
	int choice, ele, pos;
	bool isRunning = true;
	DLL *dll = createDll();
	DLL *copiedList;

	printf("1. Insertion at front\n");
	printf("2. Insertion at rear\n");
	printf("3. Insertion at position\n");
	printf("4. Deletion at front\n");
	printf("5. Deletion at rear\n");
	printf("6. Deletion at position\n");
	printf("7. Delete by key\n");
	printf("8. Search by key\n");
	printf("9. Ordered Insert\n");
	printf("10. Reverse a list\n");
	printf("11. Create a copy of the list\n");
	printf("0. Exit\n");

	while (isRunning)
	{
		printf("List Items:");
		printList(dll);

		printf("Enter choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 0:
			isRunning = false;
			break;
		case 1:
			printf("Element to insert at front\n");
			scanf("%d", &ele);
			insert_pos(dll, 0, ele);
			break;
		case 2:
			printf("Element to insert at rear\n");
			scanf("%d", &ele);
			insert_pos(dll, dll->count, ele);
			break;
		case 3:
			printf("Element to insert\n");
			scanf("%d", &ele);
			printf("Position to insert\n");
			scanf("%d", &pos);
			insert_pos(dll, pos, ele);
			break;
		case 4:
			printf("Deleting at front\n");
			delete_pos(dll, 0);
			break;
		case 5:
			printf("Deleting at rear\n");
			delete_pos(dll, dll->count-1);
			break;
		case 6:
			printf("Position to delete\n");
			scanf("%d", &pos);
			delete_pos(dll, pos);
			break;
		case 7:
			printf("Element to delete\n");
			scanf("%d", &ele);
			delete_key(dll, ele);
			break;
		case 8:
			printf("Element to Search\n");
			scanf("%d", &ele);
			search_key(dll, ele);
			break;
		case 9:
			printf("Element to insert by order\n");
			scanf("%d", &ele);
			order_inst(dll, ele);
			break;
		case 10:
			rev_list(dll);
			break;
		case 11:
			copiedList = copy_list(dll);
			printList(copiedList);
			break;
		default:
			isRunning = 0;
			break;
		}
	}
	return 0;
}


DLL *createDll()
{
	DLL *newList = (DLL *)malloc(sizeof(DLL));

	// No need to write this block
	if (!newList)
	{
		printf("Error creating Node");
		return NULL;
	}

	newList->count = 0;
	newList->head = NULL;

	return newList;
}

void insert_pos(DLL *dll, int pos, int ele)
{

	if (pos > dll->count)
	{
		printf("Invalid Position\n");
		return;
	}

	ND *newNode = createNode();
	newNode->data = ele;

	if (!dll->head)
	{
		dll->head = newNode;
	}
	else if (!pos)
	{
		newNode->rptr = dll->head;
		dll->head->lptr = newNode;
		dll->head = newNode;
	}
	else
	{
		ND *tempNode = dll->head;

		for (int i = 0; i < pos - 1; i++)
		{
			tempNode = tempNode->rptr;
		}
		newNode->rptr = tempNode->rptr;
		newNode->lptr = tempNode;
		tempNode->rptr = newNode;
	}

	(dll->count)++;
}

void printList(DLL *list)
{
	ND *tempNode = list->head;

	if (!tempNode)
	{
		printf("List is empty\n");
	}
	else
	{
		while (tempNode != NULL)
		{
			printf(" %d", tempNode->data);
			tempNode = tempNode->rptr;
		}
		printf("\n");
	}
}

void delete_pos(DLL *dll, int pos)
{
	if (pos > dll->count)
	{
		printf("Invalid Position\n");
		return;
	}

	if (!dll->head)
	{
		printf("List is empty\n");
		return;
	}

	ND *temp = dll->head;

	if (dll->count == 1 || pos == 0)
	{
		dll->head = dll->head->rptr;
		free(temp);
	}
	else
	{
		for (int i = 0; i < pos; i++)
			temp = temp->rptr;

		if (temp->lptr)
		{
			temp->lptr->rptr = temp->rptr;
		}

		if (temp->rptr)
			temp->rptr->lptr = temp->lptr;

		free(temp);
	}
	(dll->count)--;
}

void delete_key(DLL *dll, int ele)
{
	if (!dll->head)
	{
		printf("List is empty\n");
		return;
	}

	ND *temp = dll->head;
	bool isFound = false;

	while (temp)
	{
		if (temp->data == ele)
		{
			isFound = true;
			break;
		}
		temp = temp->rptr;
	}

	if (isFound)
	{
		if (!temp->lptr)
			dll->head = temp->rptr;
		else
			temp->lptr->rptr = temp->rptr;
		if (temp->rptr)
			temp->rptr->lptr = temp->lptr;

		free(temp);
		(dll->count)--;
	}
	else
	{
		printf("Element not found\n");
	}
}

void search_key(DLL *dll, int ele)
{

	ND *temp = dll->head;

	while (temp)
	{
		if (temp->data == ele)
		{
			printf("Element found\n");
			return;
		}
		temp = temp->rptr;
	}

	printf("Element not found\n");
	return;
}

void order_inst(DLL *dll, int ele)
{

	ND *temp = dll->head;

	if (!temp || temp->data > ele)
		insert_pos(dll, 0, ele);

	else
	{
		ND *newNode = createNode();
		newNode->data = ele;

		while (temp->rptr)
		{
			if (temp->rptr->data > ele)
				break;
			temp = temp->rptr;
		}

		newNode->rptr = temp->rptr;
		temp->rptr = newNode;
		newNode->lptr = temp;

		if (newNode->rptr)
			newNode->rptr->lptr = newNode;

		(dll->count)++;
	}
}

void rev_list(DLL *dll)
{
	if (!dll->head)
	{
		printf("List is empty\n");
		return;
	}
	else
	{
		ND *current, *next, *prev;
		current = dll->head;
		prev = NULL;

		while (current)
		{
			next = current->rptr;
			current->rptr = current->lptr;
			current->lptr = next;
			prev = current;
			current = next;
		}
		dll->head = prev;
	}
}

DLL *copy_list(DLL *source)
{
	if (!source->head)
	{
		printf("List is empty\n");
		return NULL;
	}

	DLL *newList = createDll();
	ND *srcNode, *destNode;
	srcNode = source->head;

	destNode = createNode();
	destNode->data = srcNode->data;
	newList->head = destNode;
	(newList->count)++;

	srcNode = srcNode->rptr;
	while (srcNode)
	{
		destNode->rptr = createNode();
		destNode->rptr->data = srcNode->data;
		destNode->rptr->lptr = destNode;

		destNode = destNode->rptr;
		srcNode = srcNode->rptr;
		(newList->count)++;
	}
	return newList;
}