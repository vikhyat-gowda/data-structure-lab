#include <stdio.h>
#include <stdlib.h>

int main()
{

    int size, ele, pos = -1;
    printf("Number of elements\n");
    scanf("%d", &size);

    int *arr = calloc(size, sizeof(int));

    printf("Enter the array element\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", arr + i);
    }

    printf("Enter the element to search\n");
    scanf("%d", &ele);

    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) == ele)
        {
            pos = i;
        }
    }

    if (pos != -1)
        printf("Element found at index %d", pos);
    else
        printf("Element not found");

    return 0;
}