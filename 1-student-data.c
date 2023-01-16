#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    char name[20];
    int reg_no;
    int marks[3];
    float avg_marks;
} student;

void read();
void display();
void average();
void bubbleSort(int a[3]);

int ne;
student s[20];
student *studentList = s;

int main()
{

    int choice;
    bool isRunning = true;

    while (isRunning)
    {
        printf("Student Data\n");
        printf("1. Enter Student Data\n");
        printf("2. Display Student Data\n");
        printf("3. Avg marks of two subjects\n");
        printf("0. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number of students\n");
            scanf("%d", &ne);
            studentList = (student *)calloc(ne, sizeof(student));
            read();
            break;
        case 2:
            display();
            break;
        case 3:
            average();
            break;
        case 0:
        default:
            isRunning = false;
            break;
        }
    }

    return 0;
}

void read()
{
    for (int i = 0; i < ne; i++)
    {
        printf("Student No %d\n", i + 1);
        printf("Enter Name: ");
        scanf("%s", studentList[i].name);
        printf("Enter Reg No: ");
        scanf("%d", &studentList[i].reg_no);
        printf("Enter marks (3 subjects): ");
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &studentList[i].marks[j]);
        }
        bubbleSort(studentList[i].marks);
        studentList[i].avg_marks = (studentList[i].marks[2] + studentList[i].marks[1]) / 2.0;
    }
}

void display()
{
    printf("\tStudents Details\n");
    for (int i = 0; i < ne; i++)
    {
        printf("Sl No: %d\n", i+1);
        printf("Name: %s\n", studentList[i].name);
        printf("RegNo: %d\n", studentList[i].reg_no);
        printf("Marks:");
        for (int j = 0; j < 3; j++)
            printf(" %d", studentList[i].marks[j]);

        printf("\nAvg: %.2f", studentList[i].avg_marks);
        printf("\n\n");
    }
}

void average()
{
    for (int i = 0; i < ne; i++)
    {
        printf("Avg of %s is %.2f\n", studentList[i].name, studentList[i].avg_marks);
    }
}

void bubbleSort(int a[3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3 - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}