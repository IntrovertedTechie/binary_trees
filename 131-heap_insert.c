#include "binary_trees.h"

/**
 * swap - Swaps two nodes
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 **/
void swap(heap_t *a, heap_t *b)
{
    int tmp = a->n;
    a->n = b->n;
    b->n = tmp;
}


heap_t *find_last_node(heap_t *root)
{
    heap_t *queue[100];
    int front = 0, rear = 0;
    heap_t *node = root;

    if (!root)
        return (NULL);

    queue[rear++] = node;

    while (front < rear)
    {
        node = queue[front++];
        if (node->left)
            queue[rear++] = node->left;
        if (node->right)
            queue[rear++] = node->right;
    }

    return (node);
}

/**
 * heapify - Maintains the Max Heap property
 * @node: Pointer to the node to heapify
 **/
void heapify(heap_t *node)
{
    heap_t *max = node;

    if (node->left && node->left->n > max->n)
        max = node->left;

    if (node->right && node->right->n > max->n)
        max = node->right;

    if (max != node)
    {
        swap(node, max);
        heapify(max);
    }
}
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *node, *parent;

    if (!root)
        return (NULL);

    node = binary_tree_node(NULL, value);
    if (!node)
        return (NULL);

    if (!*root)
    {
        *root = node;
        return (node);
    }

    parent = find_last_node(*root);

    if (!parent->left)
        parent->left = node;
    else
        parent->right = node;

    node->parent = parent;

    while (node->parent && node->n > node->parent->n)
    {
        swap(node, node->parent);
        node = node->parent;
    }

    return (node);
}

