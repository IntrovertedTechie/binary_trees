#include "binary_trees.h"

/**
 * heap_check - Check if a binary tree is a min-heap
 * @tree: A pointer to the root node of the tree to check
 * @min: The minimum allowed value for the nodes in the tree
 * @max: The maximum allowed value for the nodes in the tree
 *
 * Return: If the tree is a valid min-heap, 1, otherwise, 0
 */
int heap_check(const binary_tree_t *tree, int min, int max)
{
    if (!tree)
        return (1);

    if (tree->n < min || tree->n > max)
        return (0);

    return (heap_check(tree->left, min, tree->n - 1) &&
            heap_check(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_heap - Check if a binary tree is a min-heap
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: If the tree is a valid min-heap, 1, otherwise, 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    if (!tree->left && !tree->right)
        return (1);

    if (!tree->right)
        return (tree->n >= tree->left->n);

    if (tree->n >= tree->left->n && tree->n >= tree->right->n)
        return (heap_check(tree->left, INT_MIN, tree->n - 1) &&
                heap_check(tree->right, tree->n + 1, INT_MAX));

    return (0);
}

