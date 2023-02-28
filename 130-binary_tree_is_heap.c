#include "binary_trees.h"

/**
 * is_complete_helper - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * @index: index of the current node
 * @nodes_count: total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete_helper(const binary_tree_t *tree, int index, int nodes_count)
{
    if (tree == NULL)
        return (1);
    if (index >= nodes_count)
        return (0);
    return (is_complete_helper(tree->left, 2 * index + 1, nodes_count) &&
            is_complete_helper(tree->right, 2 * index + 2, nodes_count));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    int nodes_count;

    if (tree == NULL)
        return (0);
    nodes_count = binary_tree_nodes(tree);
    return (is_complete_helper(tree, 0, nodes_count));
}

/**
 * is_max_heap - checks if a binary tree is a valid max heap
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid max heap, 0 otherwise
 */
int is_max_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (1);
    if (tree->left != NULL && tree->left->n > tree->n)
        return (0);
    if (tree->right != NULL && tree->right->n > tree->n)
        return (0);
    return (is_max_heap(tree->left) && is_max_heap(tree->right));
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid max heap
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid max heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    if (binary_tree_is_complete(tree) == 0)
        return (0);
    return (is_max_heap(tree));
}

