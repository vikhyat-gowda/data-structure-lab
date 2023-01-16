#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} ND;

ND *createNode();
ND *createCll();

void printMenu();
void printList(ND *head);
void insertBeg(ND *head, int dataIn);
void insertEnd(ND *head, int dataIn);
void insertPos(ND *head, int pos, int dataIn);
void deleteBeg(ND *head);
void deleteEnd(ND *head);
void deletePos(ND *head, int pos);
void deleteKey(ND *head, int ele);
void reverse(ND *head);

int main()
{

    int choice, ele, pos;
    int isRunning = 1;

    ND *cll = createCll();

    printMenu();

    while (isRunning)
    {
        printf("List Items:");
        printList(cll);

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Position to insert\n");
            scanf("%d", &pos);
            printf("Element to insert\n");
            scanf("%d", &ele);
            insertPos(cll, pos, ele);
            break;

        case 2:
            printf("Position to delete\n");
            scanf("%d", &pos);
            deletePos(cll, pos);
            break;

        case 3:
            printf("Element to delete\n");
            scanf("%d", &ele);
            deleteKey(cll, ele);
            break;

        case 4:
            reverse(cll);
            break;

        case 5:
            printf("Enter the element\n");
            scanf("%d", &ele);
            insertBeg(cll, ele);
            break;

        case 6:
            printf("Enter the element\n");
            scanf("%d", &ele);
            insertEnd(cll, ele);
            break;

        case 7:
            deleteBeg(cll);
            break;

        case 8:
            deleteEnd(cll);
            break;

        case 9:
            printMenu();
            break;

        case 0:
        default:
            isRunning = 0;
        }
    }

    return 0;
}

ND *createNode()
{
    ND *newNode = (ND *)malloc(sizeof(ND));
    newNode->data = 0;
    newNode->next = NULL;

    return newNode;
}

ND *createCll()
{
    ND *newList = createNode();
    newList->next = newList;
    return newList;
}

void printMenu()
{
    char *a[] = {
        "1. Insert at pos",
        "2. Delete at pos",
        "3. Delete by key",
        "4. Reverse",
        "5. Insert at front",
        "6. Insert at rear",
        "7. Delete at front",
        "8. Delete at rear",
        "9. Print Menu",
        "0. Exit"};

    int size = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < size; i++)
    {
        printf("%s\n", a[i]);
    }
}

void printList(ND *head)
{

    if (head->next == head)
    {
        printf("List is empty\n");
        return;
    }

    ND *temp = head->next;

    while (temp != head)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertPos(ND *head, int pos, int dataIn)
{

    if (pos > head->data + 1)
    {
        printf("Invalid Position\n");
        return;
    }

    ND *newNode = createNode();
    newNode->data = dataIn;

    if (head->next == head)
    {
        head->next = newNode;
        (head->data)++;
        newNode->next = head;
    }
    else
    {
        ND *temp = head;
        int i = 1;

        while (i < pos)
        {
            temp = temp->next;
            i++;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        (head->data)++;
    }
}

void deletePos(ND *head, int pos)
{
    int i = 1;

    if (head->next == head)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        ND *temp = head->next;
        ND *prev = head;

        while (i < pos)
        {
            prev = temp;
            temp = temp->next;
            i++;
        }

        prev->next = temp->next;
        free(temp);
        (head->data)--;
    }
}

void deleteKey(ND *head, int ele)
{

    int i = 1;
    ND *temp = head->next;

    if (head->next == head)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        for (int i = 1; temp != head; (temp = temp->next) && i++)
        {
            if (temp->data == ele)
            {
                deletePos(head, i);
                return;
            }
        }
    }

    printf("Element not found\n");
}

void reverse(ND *head)
{
    if (head->next == head)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        ND *curr, *next, *prev;

        curr = next = head->next;
        prev = head;

        while (curr != head)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = prev;
    }
}

void insertBeg(ND *head, int dataIn)
{
    ND *new = createNode();
    new->data = dataIn;

    new->next = head->next;
    head->next = new;

    (head->data)++;
}

void insertEnd(ND *head, int dataIn)
{
    ND *temp = head;
    ND *new = createNode();
    new->data = dataIn;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
}

void deleteBeg(ND *head)
{
    ND *temp = head->next;
    head->next = temp->next;

    if (temp != head)
        free(temp);
}

void deleteEnd(ND *head)
{
    ND *temp = head;
    ND *dNode = NULL;

    while (temp->next->next != head)
    {
        temp = temp->next;
    }

    dNode = temp->next;
    temp->next = dNode->next;

    if (dNode != head)
        free(dNode);
}
