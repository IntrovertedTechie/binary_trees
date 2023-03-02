#include "binary_trees.h"

/**
 * swap_nodes - swaps two nodes in a binary tree
 * @node1: first node
 * @node2: second node
 */
void swap_nodes(heap_t **node1, heap_t **node2)
{
    int temp = (*node1)->n;

    (*node1)->n = (*node2)->n;
    (*node2)->n = temp;
}

/**
 * heapify - heapifies a binary tree
 * @inserted: newly inserted node
 *
 * Return: pointer to heap node
 */
heap_t *heapify(heap_t *inserted)
{
    heap_t *current = inserted;

    while (current->parent && current->n > current->parent->n)
    {
        swap_nodes(&current, &current->parent);
        current = current->parent;
    }
    return (current);
}

/**
 * binary_tree_height - calculates the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height = 0, right_height = 0;

    if (!tree)
        return (0);
    if (tree->left)
        left_height = binary_tree_height(tree->left) + 1;
    if (tree->right)
        right_height = binary_tree_height(tree->right) + 1;
    return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_size - calculates the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size.
 *
 * Return: size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to be inserted
 *
 * Return: pointer to the inserted node or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *inserted = binary_tree_node(*root, value), *current;

    if (!inserted)
        return (NULL);
    if (!*root)
        return (*root = inserted);
    current = heapify(inserted);
    if (current == inserted)
        return (inserted);

    while (current->left && current->right)
    {
        size_t left_height = binary_tree_height(current->left);
        size_t right_height = binary_tree_height(current->right);

        if (left_height == 0 || (left_height > right_height))
            current = current->left;
        else if (right_height > 0 && right_height >= left_height)
            current = current->right;
    }

    if (!current->left)
        return (current->left = inserted);
    return (current->right = inserted);
}

