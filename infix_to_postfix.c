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

void infixToPostfix(const char *infix, char *postfix)
{
    Stack stack;
    initializeStack(&stack);

    int infixLen = strlen(infix);
    int postfixIndex = 0;

    for (int i = 0; i < infixLen; i++)
    {
        char ch = infix[i];

        if (isOperator(ch))
        {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(ch))
            {
                postfix[postfixIndex++] = pop(&stack);
            }
            push(&stack, ch);
        }
        else if (ch == '(')
        {
            push(&stack, ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty(&stack) && peek(&stack) != '(')
            {
                postfix[postfixIndex++] = pop(&stack);
            }
            pop(&stack); // Discard the '('
        }
        else
        {
            postfix[postfixIndex++] = ch;
        }
    }

    while (!isEmpty(&stack))
    {
        postfix[postfixIndex++] = pop(&stack);
    }

    postfix[postfixIndex] = '\0';
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

    char postfix[MAX_SIZE];
    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
