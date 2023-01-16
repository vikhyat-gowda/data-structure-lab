#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
} ND;

ND *createNode(int data)
{
    ND *newnode = (ND *)malloc(sizeof(ND));
    newnode->rptr = NULL;
    newnode->lptr = NULL;
    newnode->data = data;

    return newnode;
}

ND *createCdll(int data)
{
    ND *newnode = (ND *)malloc(sizeof(ND));
    newnode->data = data;
    newnode->rptr = newnode->lptr = newnode;
    return newnode;
}

void display(ND *head)
{
    if (head->data == 0)
    {
        printf("List Empty\n");
        return;
    }

    ND *temp = head->rptr;
    while (temp != head)
    {
        printf(" %d", temp->data);
        temp = temp->rptr;
    }
}

void insertAtPos(ND *head, int data, int pos)
{
    ND *newNode = createNode(data);

    if (head->data == 0)
    {
        head->rptr = newNode;
        newNode->lptr = head;
        head->data++;
        newNode->rptr = head;
        return;
    }

    if (pos <= 0 || pos > (head->data) + 1)
    {
        printf("Inavlid Position\n");
        return;
    }

    if (pos == 1)
    {
        ND *temp = head->rptr;
        newNode->rptr = head->rptr;
        head->rptr = newNode;
        newNode->lptr = head;
        head->data++;
    }

    if (pos == (head->data) + 1)
    {
        ND *temp = head;
        while (temp->rptr != head)
        {
            temp = temp->rptr;
        }
        temp->rptr = newNode;
        newNode->lptr = temp;
        newNode->rptr = head;
        head->data++;
    }
    else
    {
        int i = 1;
        ND *temp = head->rptr;
        while (i < pos - 1)
        {
            temp = temp->rptr;
            i++;
        }
        newNode->rptr = temp->rptr;
        temp->rptr->lptr = newNode;
        newNode->lptr = temp;
        temp->rptr = newNode;
        head->data++;
    }
}

void removeAtPos(ND *head, int pos)
{
    if (pos <= 0 || pos >= (head->data) + 1)
    {
        printf("Inavlid Position\n");
        return;
    }

    if (pos == 1)
    {
        ND *p = head->rptr;
        head->rptr = p->rptr;
        p->rptr->lptr = head;
        free(p);
        head->data--;

        return;
    }

    ND *temp = head->rptr;
    if (pos == (head->data))
    {
        ND *p = NULL;
        while (temp->rptr != head)
        {
            p = temp;
            temp = temp->rptr;
        }
        p->rptr = temp->rptr;
    }
    else
    {
        int i = 1;
        while (i < pos)
        {
            temp = temp->rptr;
            i++;
        }
        temp->lptr->rptr = temp->rptr;
        temp->rptr->lptr = temp->lptr;
    }

    free(temp);
    head->data--;
}

void reverse(ND *head)
{

    if (head->data == 0)
    {
        printf("List is empty\n");
        return;
    }

    ND *temp = head->rptr;
    ND *p = head;
    ND *curr = NULL;

    while (temp != head)
    {
        curr = temp->rptr;
        temp->rptr = p;
        temp->lptr = curr;
        p = temp;
        temp = curr;
    }
    head->rptr = p;
}

int main()
{

    int ch, data, pos = 0, val;
    ND *head = createCdll(0);
    printf("\n1.InsertAt\n2.DeleteAt\n3.Reverse\n4.SearchByKey\n");
    while (1)
    {
        display(head);
        printf("\nEnter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data\n");
            scanf("%d", &data);
            printf("Enter Position\n");
            scanf("%d", &pos);
            insertAtPos(head, data, pos);
            break;

        case 2:
            printf("Enter Position\n");
            scanf("%d", &pos);
            removeAtPos(head, pos);
            break;

        case 3:
            reverse(head);
            break;

        case 4:
            display(head);
            break;

        default:
            break;
        }
    }
}