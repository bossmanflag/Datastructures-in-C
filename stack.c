#include <stdio.h>
#include <string.h>

int MAXSIZE = 1024;
int stack[1024];
int top = -1;

int isempty()
{

    if (top == -1)
        return 1;
    else
        return 0;
}

int isfull()
{

    if (top == MAXSIZE)
        return 1;
    else
        return 0;
}

int peek()
{
    return stack[top];
}

int pop()
{
    int data;

    if (!isempty())
    {
        data = stack[top];
        top = top - 1;
        return data;
    }
    else
    {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

int pushStack(int data)
{

    if (!isfull())
    {
        top = top + 1;
        stack[top] = data;
    }
    else
    {
        printf("Could not insert data, Stack is full.\n");
    }
}

char *processString(char string[1024])
{
    size_t length = strlen(string);
    size_t i = 0;
    for (; i < length; i++)
    {
        if (string[i] == '#')
        {
            int popval = pop();
            printf("backspacing...");
        }
        else
        {
            int x = (int)string[i];
            pushStack(x);
            printf("%c ", string[i]); /* Print each character of the string. */
        }
    }
}
void printString()
{
    int i = 0;
    char str[1024];
    while (!isempty())
    {
        int data = pop();
        char c = (char)data;
        //printf("%c ", c);
        str[i] = c;
        i++;
    }
    //printf("%s", str);
    printf("\nFinal String: ");
    for (int g = strlen(str) - 1; g >= 0; g--)
    {
        printf("%c", str[g]);
    }
    printf("\n");
}

int stackImplementation(char str[1024])
{

    processString(str);
    printString();

    return 0;
}