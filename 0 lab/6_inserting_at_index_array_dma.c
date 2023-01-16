#include <stdio.h>
#include <stdlib.h>

int main()
{

    int size, ele, pos;

    printf("Number of elements\n");
    scanf("%d", &size);

    int *arr = (int *)calloc(size, sizeof(int));

    printf("Enter the array elements\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Index to insert: ");
    scanf("%d", &pos);

    printf("Element to Insert: ");
    scanf("%d", &ele);

    if (pos > size)
    {
        printf("Invalid Position");
        return -1;
    }

    int n = size;
    size += 1;
    arr = realloc(arr, size * sizeof(int));

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

    free(arr);

    return 0;
}