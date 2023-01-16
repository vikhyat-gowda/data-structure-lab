#include <stdio.h>
#include <stdlib.h>

struct ND
{
    int data;
    struct ND *next;
};

struct ND *createLL();
void createNode(struct ND *newNode);

int main()
{

    struct ND *head = createLL();
    struct ND *newNode = NULL;

    // Create a node
    createNode(newNode);

    // link new node to head
    if (head->next == NULL)
        head->next = newNode;

    return 0;
}

struct ND *createLL()
{
    struct ND *head;
    createNode(head);
    return head;
}

void createNode(struct ND *newNode)
{
    newNode = (struct ND *)malloc(sizeof(struct ND));
    newNode->data = 0;
    newNode->next = NULL;
}