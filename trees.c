#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

// Create a node
struct node *newNode(int item)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->key = item;
    t->left = t->right = NULL;
    return t;
}

// Inorder Traversal
void inorderTraversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorderTraversal(root->left);
        printf("%d -> ", root->key);
        inorderTraversal(root->right);
    }
}

struct node *insertval(struct node *node, int data)
{
    if (node == NULL)
        return newNode(data);

    if (data > node->key)
        node->right = insertval(node->right, data);
    else
        node->left = insertval(node->left, data);

    return node;
}

struct node *minval(struct node *node)
{
    struct node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
void print2D(struct node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    print2D(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    // Process left child
    print2D(root->left, space);
}

// int main()
// {
//     struct node *root = NULL;
//     root = insertval(root, 8);
//     root = insertval(root, 3);
//     root = insertval(root, 1);
//     root = insertval(root, 6);
//     root = insertval(root, 7);
//     root = insertval(root, 10);
//     root = insertval(root, 14);
//     root = insertval(root, 4);

//     printf("Inorder traversal: ");
//     inorderTraversal(root);
//     printf("\n");
//     print2D(root, 0);
// }