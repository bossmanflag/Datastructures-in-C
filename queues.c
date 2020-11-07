
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct node
{
    int data;
    struct node *previous;
} * node_ptr;

node_ptr front = NULL;
node_ptr rear = NULL;

bool is_empty()
{
    return (front == NULL);
}

bool enqueue(int value)
{
    FILE *fp;
    char filename[50];
    sprintf(filename, "printerFiles/%d.txt", value);
    fp = fopen(filename, "w+");
    fprintf(fp, "This is testing for fprintf...\n");
    fputs("This is testing for fputs...\n", fp);
    fclose(fp);
    node_ptr item = (node_ptr)malloc(sizeof(struct node));

    if (item == NULL)
        return false;

    item->data = value;
    item->previous = NULL;

    if (rear == NULL)
        front = rear = item;
    else
    {
        rear->previous = item;
        rear = item;
    }

    return true;
}

int dequeue()
{

    if (is_empty())
    {
        printf("\nThe queue is empty! Add some files\n");
        return -1;
    }
    char filename[50];
    node_ptr temp = front;
    front = front->previous;
    int value = temp->data;
    sprintf(filename, "printerFiles/%d.txt", value);
    remove(filename);
    return value;
}

int isDirectoryExists(const char *path)
{
    struct stat stats;

    stat(path, &stats);
    if (S_ISDIR(stats.st_mode))
        return 1;

    return 0;
}

void queuesImplementation()
{
    srand(0);
    int option = 0, value = 0;
    printf("Printer Spooler \n");
    int check;
    int interval = 1;
    int choice = 0;
    char *dir_name = "printerFiles";
    check = mkdir(dir_name, 0777);
    if (!check || isDirectoryExists("printerFiles"))
    {
        printf("Directory created \n");
        printf("1. add files \n");
        printf("2. continue...\n");
        scanf("%d", &choice);
        while (choice == 1 || choice == 2 || choice == 3)
        {
            if (choice == 1)
            {
                printf("Adding files...\n");
                enqueue(rand() % 50);
                printf("Files Added...\n");
                printf("1. add files \n");
                printf("2. continue...\n");

                scanf("%d", &choice);
            }
            else if (choice == 2)
            {
                printf("Time Interval: %d\n", interval);
                int d = dequeue();
                if (d != -1)
                {
                    printf("Now printing: %d\n", d);
                }
                interval++;
                printf("1. add files \n");
                printf("2. continue...\n");

                scanf("%d", &choice);
            }

            else
            {
                break;
            }
        }
    }
    else
    {
        printf("Directory failed to create \n");
        exit(1);
    }
}