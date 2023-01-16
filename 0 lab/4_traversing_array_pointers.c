#include <stdio.h>
#include <stdlib.h>

int main()
{

    int size;
    printf("Enter the number of elements\n");
    scanf("%d", &size);

    int *arr = calloc(size, sizeof(int));

    printf("Enter the array elements\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", arr + i);
    }

    printf("The array elements are: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(arr + i));
    }

    return 0;
}

/*
Enter the number of elements
4
Enter the array elements
1 2 3 4
The array elements are: 
1 2 3 4
*/