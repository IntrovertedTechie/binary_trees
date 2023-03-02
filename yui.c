#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure the size.
 *
 * Return: Size of the binary tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height >= right_height)
		return (left_height + 1);
	return (right_height + 1);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 *
 * @root: Double pointer to the root node of the Heap.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Pointer to the inserted node or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	int tmp;

	if (!root)
		return (NULL);

	if (!*root)
	{
		new_node = binary_tree_node(NULL, value);
		if (!new_node)
			return (NULL);
		*root = new_node;
		return (new_node);
	}

	parent = (heap_t *)binary_tree_node(NULL, 0);
	if (!parent)
		return (NULL);
	parent->left = *root;
	new_node = binary_tree_node(parent, value);
	if (!new_node)
	{
		free(parent);
		return (NULL);
	}

	if (parent->left)
		parent->left->parent = new_node;
	parent->left = new_node;

	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		tmp = new_node->parent->n;
		new_node->parent->n = new_node->n;
		new_node->n = tmp;
		new_node = new_node->parent;
	}

	free(parent);

	return (new_node);
}

