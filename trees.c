#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create a TreeNode
struct TreeNode *newTreeNode(int item)
{
    struct TreeNode *t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    t->key = item;
    t->left = t->right = NULL;
    return t;
}

// Inorder Traversal
void inorderTraversal(struct TreeNode *root)
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

struct TreeNode *insertval(struct TreeNode *TreeNode, int data)
{
    if (TreeNode == NULL)
        return newTreeNode(data);

    if (data > TreeNode->key)
        TreeNode->right = insertval(TreeNode->right, data);
    else
        TreeNode->left = insertval(TreeNode->left, data);

    return TreeNode;
}

struct TreeNode *minval(struct TreeNode *TreeNode)
{
    struct TreeNode *current = TreeNode;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
void print2D(struct TreeNode *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    print2D(root->right, space);

    // Print current TreeNode after space
    // count
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    // Process left child
    print2D(root->left, space);
}

void treeImplementation()
{
    struct TreeNode *root = NULL;
    int val = 0;
    while (1)
    {
        printf("Start? ");
        printf("Enter All the values for the binary tree: ");
        scanf("%d ", &val);
        if (val != -1)
        {
            root = insertval(root, val);
        }
        else
        {
            break;
        }
    }
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    print2D(root, 0);
}