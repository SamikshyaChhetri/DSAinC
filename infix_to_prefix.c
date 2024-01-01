#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct
{
    char items[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack)
{
    stack->top = -1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

char peek(Stack *stack)
{
    return stack->items[stack->top];
}

void push(Stack *stack, char value)
{
    stack->items[++stack->top] = value;
}

char pop(Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->items[stack->top--];
    }
    return '\0';
}

int isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}

void infixToPrefix(const char *infix, char *prefix)
{
    Stack stack;
    initializeStack(&stack);

    int infixLen = strlen(infix);
    int prefixIndex = 0;

    for (int i = infixLen - 1; i >= 0; i--)
    {
        char ch = infix[i];

        if (isOperator(ch))
        {
            while (!isEmpty(&stack) && precedence(peek(&stack)) > precedence(ch))
            {
                prefix[prefixIndex++] = pop(&stack);
            }
            push(&stack, ch);
        }
        else if (ch == ')')
        {
            push(&stack, ch);
        }
        else if (ch == '(')
        {
            while (!isEmpty(&stack) && peek(&stack) != ')')
            {
                prefix[prefixIndex++] = pop(&stack);
            }
            pop(&stack); // Discard the ')'
        }
        else
        {
            prefix[prefixIndex++] = ch;
        }
    }

    while (!isEmpty(&stack))
    {
        prefix[prefixIndex++] = pop(&stack);
    }

    prefix[prefixIndex] = '\0';

    // Reverse the prefix to get the correct order
    int start = 0;
    int end = prefixIndex - 1;
    while (start < end)
    {
        char temp = prefix[start];
        prefix[start] = prefix[end];
        prefix[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    char infix[MAX_SIZE];
    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    if (infix[strlen(infix) - 1] == '\n')
    {
        infix[strlen(infix) - 1] = '\0';
    }

    char prefix[MAX_SIZE];
    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
