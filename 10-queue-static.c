#include <stdio.h>

#define MAX 20

int queue[MAX];
int front = -1;
int rear = -1;

int dequeu();
void print();
void enqueue(int data);

int main()
{
    int choice;
    int ele;
    int isRunning = 1;

    while (isRunning)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        scanf("%d", &choice);
        print();
        switch (choice)
        {
        case 1:
            printf("Enter the element\n");
            scanf("%d", &ele);
            enqueue(ele);
            break;
        case 2:
            printf("Removed Element: %d\n", dequeu());
        default:
            isRunning = 0;
            break;
        }
    }
    return 0;
}

void enqueue(int data)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    queue[++rear] = data;
}

int dequeu()
{
    if (front == MAX - 1)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    return queue[front++];
}

void print()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}