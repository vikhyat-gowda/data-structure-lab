#include <stdio.h>

int main()
{

    int a, b;
    int *p, *q;

    printf("Enter 2 numbers\n");
    scanf("%d %d", &a, &b);

    p = &a;
    q = &b;

    printf("Operations using pointers\n");
    printf("Sum = %d\n", (*p) + (*q));
    printf("Difference = %d\n", (*p) - (*q));
    printf("Multiplication = %d\n", (*p) * (*q));

    printf("\n\nUsing * and &\n");
    printf("Sum = %d\n", *(&a) + *(&b));
    printf("Difference = %d\n", *(&a) - *(&b));
    printf("Multiplication = %d\n", *(&a) * *(&b));

    return 0;
}

/*
Enter 2 numbers
2 3
Operations using pointers
Sum = 5
Difference = -1
Multiplication = 6


Using * and &
Sum = 5
Difference = -1
Multiplication = 6
*/