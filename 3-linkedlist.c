#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ND
{
    int data;
    struct ND *next;
} ND;

typedef struct
{
    int count;
    ND *head;
} LL;

ND *createNode();
LL *createList();
void printList(LL *list);
void insertPos(LL *list, int ele, int pos);
void removePos(LL *list, int pos);
void listReverse(LL *list);
void insertOrder(LL *list, int ele);
void searchList(LL *list, int ele);
void removeEle(LL *list, int ele);
LL *copyList(LL *source);

LL *createList()
{
    LL *newList = (LL *)malloc(sizeof(LL));

    newList->count = 0;
    newList->head = NULL;

    return newList;
}

ND *createNode()
{
    ND *newNode = (ND *)malloc(sizeof(ND));

    newNode->next = NULL;
    newNode->data = 0;
    return newNode;
}

void searchInsert(LL *list, int X)
{
    int isFouned = 0;

    if (!list->head)
    {
        printf("List is empty");
        return;
    }

    ND *temp = list->head, *prev;

    while (temp)
    {
        if (temp->data == X)
        {
            isFouned = 1;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (isFouned)
    {
        printf("Element already exist\n");
        return;
    }

    ND *newNode = createNode();
    newNode->data = X;
    prev->next = newNode;
}

void removeInsert(LL *list)
{
    if (!list->head)
    {
        printf("List is empty");
        return;
    }
    ND *firstNode = list->head;
    list->head = firstNode->next;
    ND *temp = list->head, *prev = NULL;

    while (temp)
    {
        prev = temp;
        temp = temp->next;
    }

    if (prev)
    {
        prev->next = firstNode;
        firstNode->next = NULL;
    }

    if (!list->head)
        list->head = firstNode;
}

int main()
{
    int choice, ele, pos;
    bool isRunning = true;
    LL *list = createList(), *copiedList;

    insertPos(list, 4, 0);
    printList(list);
    insertPos(list, 8, 0);
    printList(list);
    removePos(list, 1);
    printList(list);

    // printf("\t\tLinked List\n");
    // printf("0. Exit\n");
    // printf("1. Print List\n");
    // printf("2. Insertion at front\n");
    // printf("3. Insertion at rear\n");
    // printf("4. Deletion at front\n");
    // printf("5. Deletion at rear\n");
    // printf("6. Insertion by key\n");
    // printf("7. Deletion by position\n");
    // printf("8. Search by key\n");
    // printf("9. Insert by order\n");
    // printf("10. Reverse List\n");
    // printf("11. Creating a copy of the list\n");
    // printf("12. Delete by element\n");
    // while (isRunning)
    // {
    //     printf("Enter choice: ");
    //     scanf("%d", &choice);

    //     switch (choice)
    //     {
    //     case 1:
    //         printList(list);
    //         removeInsert(list);
    //         break;
    //     case 2:
    //         printf("Element to insert at front\n");
    //         scanf("%d", &ele);
    //         insertPos(list, ele, 0);
    //         printList(list);
    //         break;
    //     case 3:
    //         printf("Element to insert at Rear\n");
    //         scanf("%d", &ele);
    //         insertPos(list, ele, list->count);
    //         printList(list);
    //         break;
    //     case 4:
    //         removePos(list, 0);
    //         printList(list);
    //         break;
    //     case 5:
    //         removePos(list, list->count - 1);
    //         printList(list);
    //         break;
    //     case 6:
    //         printf("Position to insert\n");
    //         scanf("%d", &pos);
    //         printf("Element to insert\n");
    //         scanf("%d", &ele);
    //         insertPos(list, ele, pos);
    //         printList(list);
    //         break;
    //     case 7:
    //         printf("Enter the pos\n");
    //         scanf("%d", &pos);
    //         removePos(list, pos);
    //         printList(list);
    //         break;
    //     case 8:
    //         printf("Element to search\n");
    //         scanf("%d", &ele);
    //         searchList(list, ele);
    //         break;
    //     case 9:
    //         printf("Element to insert\n");
    //         scanf("%d", &ele);
    //         insertOrder(list, ele);
    //         printList(list);
    //         break;
    //     case 10:
    //         listReverse(list);
    //         printList(list);
    //         break;
    //     case 11:
    //         copiedList = copyList(list);
    //         printf("New List");
    //         printList(copiedList);
    //         break;
    //     case 12:
    //         printf("Enter the ele\n");
    //         scanf("%d", &pos);
    //         removeEle(list, pos);
    //         printList(list);
    //         break;
    //     case 0:
    //     default:
    //         isRunning = false;
    //         break;
    //     }
    // }
    return 0;
}

void insertPos(LL *list, int ele, int pos)
{
    if (pos > list->count)
    {
        printf("Invalid Pos\n");
        return;
    }

    ND *tempNode = list->head;
    ND *newNode = createNode();
    newNode->data = ele;

    if (!pos || !list->count)
    {
        newNode->next = tempNode;
        list->head = newNode;
    }
    else
    {
        for (int i = 0; i < (pos - 1); i++)
        {
            tempNode = tempNode->next;
        }
        newNode->next = tempNode->next;
        tempNode->next = newNode;
    }
    (list->count)++;
}

void printList(LL *list)
{
    ND *tempNode = list->head;

    if (!tempNode)
    {
        printf("List is empty\n");
        return;
    }

    while (tempNode != NULL)
    {
        printf(" %d", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

void removePos(LL *list, int pos)
{
    if (!list->head)
        return;

    if (pos >= list->count)
    {
        printf("Invalid Pos\n");
        return;
    }

    ND *tempNode = list->head, *deletingNode;

    if (pos == 0)
    {
        deletingNode = tempNode;
        list->head = tempNode->next;
        free(deletingNode);
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            tempNode = tempNode->next;
        }
        deletingNode = tempNode->next;
        tempNode->next = deletingNode->next;
        free(deletingNode);
    }

    (list->count)--;
}

void listReverse(LL *list)
{
    if (!list->head)
    {
        printf("List is empty\n");
        return;
    }

    ND *prevNode = NULL, *currentNode, *nextNode;
    currentNode = nextNode = list->head;

    while (nextNode)
    {
        nextNode = nextNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    list->head = prevNode;
}

LL *copyList(LL *source)
{
    LL *newList = createList();

    ND *tempNode = source->head;

    while (tempNode)
    {
        insertPos(newList, tempNode->data, newList->count);
        tempNode = tempNode->next;
    }

    return newList;
}

void insertOrder(LL *list, int ele)
{
    ND *tempNode = list->head;
    ND *newNode = createNode();
    newNode->data = ele;

    if (!tempNode || tempNode->data > ele)
    {
        newNode->next = tempNode;
        list->head = newNode;
    }
    else
    {

        while (tempNode->next)
        {
            if (tempNode->next->data > ele)
                break;
            tempNode = tempNode->next;
        }

        newNode->next = tempNode->next;
        tempNode->next = newNode;
    }
    (list->count)++;
}

void searchList(LL *list, int ele)
{
    ND *tempNode = list->head;

    while (tempNode)
    {
        if (tempNode->data == ele)
        {
            printf("Element found!!\n");
            return;
        }
        tempNode = tempNode->next;
    }

    printf("Element not found\n");
}

void removeEle(LL *list, int ele)
{
    ND *tempNode = list->head;

    if (!tempNode)
    {
        printf("List is empty\n");
        return;
    }

    ND *prevNode = tempNode;

    if (tempNode->data == ele)
    {
        list->head = tempNode->next;
        free(tempNode);
        return;
    }
    else
    {
        while (tempNode && tempNode->data != ele)
        {
            prevNode = tempNode;
            tempNode = tempNode->next;
        }

        if (!tempNode)
            return;

        prevNode->next = tempNode->next;
        free(tempNode);
    }
}