#include <stdio.h>
#include <stdlib.h>
typedef struct ll_node
{
    int val;
    struct ll_node *next;
} node_t;
void print_list(node_t *head)
{
    node_t *current = head;
    while (current != NULL)
    {
        printf("%d.com->", current->val);
        current = current->next;
    }
    printf("\n");
}
void push(node_t *head, int val)
{
    node_t *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (node_t *)malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}
int remove_last(node_t *head)
{
    int retval = 0;
    /* if there is only one item in the list, remove it */
    if (head->next == NULL)
    {
        retval = head->val;
        free(head);
        return retval;
    }

    /* get to the second to last node in the list */
    node_t *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;
}
int linkedListImplementation()
{
    node_t *list = (node_t *)malloc(sizeof(node_t));
    int choice = 0;
    while (choice != 99)
    {
        printf("1. going forward to a new webpage\n");
        printf("2. going back\n");
        printf("99. exit\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int r = rand() % 100;
            printf("Visiting new Website: %d.com\n", r);
            push(list, r);
            print_list(list->next);
        }
        else if (choice == 2)
        {
            int r = rand() % 100;
            printf("Going back to Website: %d.com\n", remove_last(list));
            print_list(list->next);
        }
        else
        {
            printf("Exiting...");
            break;
        }
    }
}