#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int top = -1;
char st[MAX];


void push(char x);
char pop();
int getPriority(char c);
void infixToPostfix(char infix[MAX], char postfix[MAX]);


void push(char x)
{
    st[++top] = x;
}


char pop()
{
    if (top != -1)
        return st[top--];
    return -1;
}


int getPriority(char c)
{
    switch (c)
    {
    case '^':
        return 4;
    case '*':
    case '/':
        return 3;
    case '+':
    case '-':
        return 2;
    default:
        return 1;
    }
}


void infixToPostfix(char infix[MAX], char postfix[MAX])
{
    char temp, x;

    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        temp = infix[i];

        if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((x = pop()) != '(')
            {
                postfix[j++] = x;
            }
        }
        else if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else
        {
            if (top != -1 && (getPriority(infix[i]) <= getPriority(st[top])))
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }

        i++;
    }

    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
}


void infixToPrefix(char infix[MAX],char prefix[MAX])
{
    strrev(infix);

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if(infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }


    infixToPostfix(infix, prefix);
    strrev(prefix);
}

int main()
{
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter the infix expression\n");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("The postfix expression is %s \n", postfix);

    infixToPrefix(infix, prefix);
    printf("The prefix expression is %s \n", prefix);

    return 0;
}