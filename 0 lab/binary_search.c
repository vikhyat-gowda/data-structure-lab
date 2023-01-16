#include <stdio.h>

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    int ele = 0;
    int size = 5;
    int pos = -1, mid, hi, lo;

    hi = size - 1;
    lo = 0;

    while (lo <= hi)
    {
        mid = (hi + lo) / 2;

        if (arr[mid] > ele)
        {
            hi = mid - 1;
        }
        else if (arr[mid] < ele)
        {
            lo = mid + 1;
        }
        else
        {
            pos = mid + 1;
            printf("Element found at pos %d", pos);
            break;
        }
    }

    if (pos == -1)
        printf("Element not found");

    return 0;
}