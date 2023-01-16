#include <stdio.h>
#include <stdlib.h>

int main()
{

    int size, pos;

    printf("Number of elements\n");
    scanf("%d", &size);

    int *arr = (int *)calloc(size, sizeof(int));

    printf("Enter the array elements\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", arr + i);
    }

    printf("Index to delete: ");
    scanf("%d", &pos);

    if (pos >= size)
    {
        printf("Invalid Position");
        return -1;
    }

    for (int i = pos; i < size; i++)
        *(arr + i) = *(arr + i + 1);

    size--;
    arr = realloc(arr, size * sizeof(int));

    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(arr + i));
    }

    free(arr);

    return 0;
}