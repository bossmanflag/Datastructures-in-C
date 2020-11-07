#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define HASHTABLE_H 1
typedef struct
{
    int key;
    int value;
} * document;
void init(void);
void insert(document);
document search(int);
void delete (int);

#define M 197

// Our record table definition, an array of M records.
document ht[M];

static int hash(int key)
{
    return (key % M);
}

void init()
{
    int i;
    for (i = 0; i < M; ++i)
    {
        ht[i] = NULL;
    }
}

void insert(document r)
{
    int i = hash(r->key);
    while (ht[i] != NULL)
    {
        i = (i + 1) % M;
    }
    ht[i] = r;
}

document search(int key)
{
    int i = hash(key);
    while (ht[i] != NULL)
    {
        if (key == ht[i]->key)
        {
            return ht[i];
        }
        else
        {
            i = (i + 1) % M;
        }
    }
    return NULL;
}

void delete (int key)
{
    int i = hash(key);
    document r;
    while (ht[i] != NULL)
    {
        if (key == ht[i]->key)
        {
            break;
        }
        else
        {
            i = (i + 1) % M;
        }
    }
    if (ht[i] == NULL)
    {
        return;
    }
    ht[i] = NULL;
    for (i = (i + 1) % M; ht[i] != NULL; i = (i + 1) % M)
    {
        r = ht[i];
        ht[i] = NULL;
        insert(r);
    }
}
void implementHashTable()
{
    int i;
    document a;

    srand(time(NULL));

    // Initialize the hash table
    init();

    // Insert N random records
    for (i = 0; i < 50; ++i)
    {

        // Generate new random record
        a = malloc(sizeof(*a));
        a->key = rand() % 1000;
        a->value = rand() % 1000;

        // Don't allow duplicate keys
        if (search(a->key) != NULL)
        {
            --i;
            continue;
        }

        // Insert new record
        printf("Inserting: Key => %i, Value => %i\n", a->key, a->value);
        insert(a);
    }

    // Search and delete records for all possible keys
    for (i = 0; i < 1000; ++i)
    {
        if ((a = search(i)) != NULL)
        {
            printf("Deleting: Key => %i, Value => %i\n", a->key, a->value);
            delete (a->key);
        }
    }

}