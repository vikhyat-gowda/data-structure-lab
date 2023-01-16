#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int h;
    int min;
    int sec;
} Time;

Time readTime();
void printTime(Time t);
void updateTime(Time *t, int incr);
Time *addTime(Time T1, Time T2);

int main()
{

    int choice;
    int isRunning = 1;
    Time t, *sum;

    while (isRunning)
    {
        printf("Time\n");
        printf("1.Read\n");
        printf("2.Display\n");
        printf("3.Update Time\n");
        printf("4.Add two Time\n");
        printf("0.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            t = readTime();
            break;
        case 2:
            printTime(t);
            break;
        case 3:
            printf("Before: ");
            printTime(t);
            updateTime(&t, 1);
            printf("After: ");
            printTime(t);
            break;
        case 4:
            sum = addTime(readTime(), readTime());
            printf("Time: %2d:%2d:%2d\n", sum->h, sum->min, sum->sec);
            break;
        case 0:
        default:
            isRunning = 0;
            break;
        }
    }
    return 0;
}

Time readTime()
{
    Time nT;
    printf("Enter time (hh mm ss) format\n");
    scanf("%d %d %d", &nT.h, &nT.min, &nT.sec);

    updateTime(&nT, 0);

    return nT;
}

void printTime(Time t)
{
    printf("Time: %2d:%2d:%2d\n", t.h, t.min, t.sec);
}

void updateTime(Time *t, int incr)
{
    (t->sec) += incr;
    if (t->sec >= 60)
    {
        t->sec %= 60;
        (t->min)++;
    }
    if (t->min >= 60)
    {
        t->min %= 60;
        (t->h)++;
    }
    if (t->h >= 24)
    {
        t->h = 0;
        t->min = 0;
        t->sec = 0;
    }
}

Time *addTime(Time T1, Time T2)
{

    Time *rt = (Time *)malloc(sizeof(Time));
    rt->h = rt->min = rt->sec = 0;

    rt->sec = T1.sec + T2.sec;
    rt->min = T1.min + T2.min;
    rt->h = T1.h + T2.h;
    updateTime(rt, 0);

    return rt;
}
