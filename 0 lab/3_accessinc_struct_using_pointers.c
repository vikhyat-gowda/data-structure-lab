#include <stdio.h>

struct employee
{
    char name[20];
    int id;
    int salary;
};

int main()
{

    struct employee e;
    struct employee *emp = &e;

    printf("Enter the name of the employee\n");
    scanf("%s", emp->name);

    printf("Enter the id of the employee\n");
    scanf("%d", &(emp->id));

    printf("Enter the salary of the employee\n");
    scanf("%d", &(emp->salary));

    printf("Employee Details\n");
    printf("Name: %s  Id: %d  Salary: %d", emp->name, emp->id, emp->salary);

    return 0;
}

/*
Enter the name of the employee
John
Enter the id of the employee
233
Enter the salary of the employee
32999
Employee Details
Name: John  Id: 233  Salary: 32999
*/