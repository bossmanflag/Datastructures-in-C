#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.c"
#include "stack.c"
#include "trees.c"

int main()
{
    int ch;
    char str[1024];

    printf("Choose which data structure you want to explore \n1.Stacks\n2.Linked Lists\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:

        printf("Enter a String, use # for backspace\n");
        scanf("%s", str);
        stackImplementation(str);
        break;
    case 2:
        linkedListImplementation();

    default:
        break;
    }
    return 0;
}
