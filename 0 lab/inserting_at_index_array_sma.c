#include <stdio.h>
#include <stdlib.h>

int main()
{

    int size, ele, pos;
    int arr[100];

    printf("Enter the number of elements\n");
    scanf("%d", &size);

    printf("Enter the array elements\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the index to insert: ");
    scanf("%d", &pos);

    printf("Enter the element to Insert: ");
    scanf("%d", &ele);

    if (pos > size)
    {
        printf("Invalid Position");
        return -1;
    }

    int n = size;
    size += 1;

    while (pos <= n)
    {
        arr[n + 1] = arr[n];
        n--;
    }
    arr[pos] = ele;

    printf("Element inserted at index %d\n", pos);

    printf("The array elements are: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}