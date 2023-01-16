#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ND
{
    int data;
    struct ND *next;
} ND;

ND *createNode(int val)
{
    ND *newNode = (ND *)malloc(sizeof(ND));
    newNode->data = val;
    newNode->next = newNode;

    return newNode;
}

// deleting a successor of kth node if its not head
void delete(ND *head, int k)
{
    if (k >= head->data)
    {
        printf("Invalid Position \n");
        return;
    }

    ND *temp = head->next;
    if (k == 0)
    {
        head->next = temp->next;
        free(temp);
    }
    else
    {
        for (int i = 1; i < k; i++)
            temp = temp->next;

        ND *dlN = temp->next;
        temp->next = dlN->next;
        free(dlN);
    }
    (head->data)--;
}

// insert a new node to the left of the kth predecessor node
void insert(ND *head, int k)
{
    if (k == 0 || k > head->data)
    {
        printf("Invalid position\n");
        return;
    }

    if (k == 1)
    {
        ND *newNode = createNode(99);
        newNode->next = head->next;
        head->next = newNode;
    }
    else
    {
        ND *temp = head->next;
        for (int i = 1; i < k - 1; i++)
        {
            temp = temp->next;
        }
        ND *newNode = createNode(100);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    (head->data)++;
}

void printList(ND *head)
{
    ND *temp = head->next;
    while (temp != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Temp function for testing
ND *set()
{
    ND *head = createNode(4);
    ND *node1 = createNode(3);
    ND *node2 = createNode(4);
    ND *node3 = createNode(5);
    ND *node4 = createNode(6);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = head;
    return head;
}

void insert_pos(ND *head, int pos, int ele)
{
    ND *newNode = createNode(ele);

    if (pos > head->data)
    {
        printf("Invalid position\n");
        return;
    }

    if (head->next == head)
    {
        head->next = newNode;
        newNode->next = head;
        (head->data)++;
    }
    else
    {
        ND *tempNode = head->next;
        for (int i = 0; i < pos - 1; i++)
            tempNode = tempNode->next;

        newNode->next = tempNode->next;
        tempNode->next = newNode;
        (head->data)++;
    }
}

void delete_pos(ND *head, int pos)
{
    if (head->next == head)
    {
        printf("Empty List\n");
        return;
    }

    if (pos >= head->data)
    {
        // printf("Invalid Pos\n");
        return;
    }

    ND *temp = head->next;
    if (pos == 0)
    {
        head->next = temp->next;
        free(temp);
    }
    else
    {
        ND *deletingNode;
        for (int i = 1; i < pos; i++)
            temp = temp->next;

        deletingNode = temp->next;
        temp->next = deletingNode->next;
        free(deletingNode);
    }
    (head->data)--;
}

void deletePos2(ND *head, int pos)
{
    if (pos > head->data || pos == 0)
    {
        printf("Error delete");
        return;
    }

    int i = 1;
    ND *temp, *DN;
    temp = head;

    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    DN = temp->next;
    temp->next = DN->next;
    free(DN);
    (head->data)--;
}

void insertPos2(ND *head, int pos, int ele)
{
    if (pos > head->data+1)
    {
        printf("Error insert\n");
        return;
    }

    int i = 1;
    ND *temp = head;
    ND *newNode = createNode(ele);
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    (head->data)++;
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));
    ND *head = createNode(0);
    int size = 4;
    insertPos2(head, 1, 44);
    printList(head);
    insertPos2(head, 1, 56);
    printList(head);
    

    return 0;
}
