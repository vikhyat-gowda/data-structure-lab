#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char a[MAX];
int top = -1;

char pop();
int isEmpty();
void push(char c);
int getResult(int n1, int n2, char op);
int postfixEvaluation(char postfix[MAX]);
int prefixEvaluation(char prefix[MAX]);

int main()
{

    char postfix[MAX];
    int result;

    printf("1.Postfix Evaluation\n");
    printf("2.Prefix Evaluation\n");
    printf("Enter choice: ");
    scanf("%d", &result);

    switch (result)
    {
    case 1:
        printf("Enter expression: ");
        scanf("%s", postfix);
        result = postfixEvaluation(postfix);
        break;
    case 2:
        printf("Enter expression: ");
        scanf("%s", postfix);
        result = prefixEvaluation(postfix);
        break;
    }

    printf("Result: %d\n", result);

    return 0;
}

void push(char c)
{
    a[++top] = c;
}

char pop()
{
    if (top != -1)
        return a[top--];
    return top;
}

int isEmpty()
{
    return top == -1;
}

int getResult(int n1, int n2, char op)
{
    switch (op)
    {
    case '*':
        return n1 * n2;
    case '/':
        return n1 / n2;
    case '+':
        return n1 + n2;
    case '-':
        return n1 - n2;
    }
}

int postfixEvaluation(char postfix[MAX])
{
    int i = 0, i1, i2;
    int result = 0;

    while (postfix[i] != '\0')
    {
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            i2 = pop();
            i1 = pop();

            result = getResult(i1, i2, postfix[i]);
            push(result);
        }

        i++;
    }
    return result;
}

int prefixEvaluation(char prefix[MAX])
{
    strrev(prefix);
    return postfixEvaluation(prefix);
}