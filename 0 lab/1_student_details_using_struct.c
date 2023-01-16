#include <stdio.h>

struct student
{

    char name[20];
    int rollno;
    float marks[3];
};

int main()
{
    const int size = 2;

    struct student s[size];

    printf("\nEnter Details of %d student\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter the name: ");
        scanf("%s", s[i].name);

        printf("\nEnter the roll no: ");
        scanf("%d", &s[i].rollno);

        printf("\nEnter the marks of 3 subjects: ");
        for (int j = 0; j < 3; j++)
        {
            scanf("%f", &s[i].marks[j]);
        }
    }

    printf("\nDetails of %d student\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("Name: %s\n", s[i].name);
        printf("Roll No: %d\n", s[i].rollno);
        printf("Marks: ");

        float avg = 0;

        for (int j = 0; j < 3; j++)
        {
            printf("%f ", s[i].marks[j]);
            avg += s[i].marks[j];
        }

        avg /= 3.0;

        printf("\nAverage: %.2f\n\n", avg);
    }

    return 0;
}

/*
Enter Details of 2 student
Enter the name: john
Enter the roll no: 2
Enter the marks of 3 subjects: 33 43 54

Enter the name: Jack
Enter the roll no: 3
Enter the marks of 3 subjects: 43 46 44

Details of 2 student
Name: john
Roll No: 2
Marks: 33.000000 43.000000 54.000000
Average: 43.33

Name: Jack
Roll No: 3
Marks: 43.000000 46.000000 44.000000
Average: 44.33
*/