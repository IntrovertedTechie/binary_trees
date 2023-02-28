#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root, *node;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 90);
    root->right = binary_tree_node(root, 85);
    root->left->right = binary_tree_node(root->left, 80);
    root->left->left = binary_tree_node(root->left, 79);

    binary_tree_print(root);
    printf("Is %d heap: %d\n", root->n, binary_tree_is_heap(root));
    printf("Is %d heap: %d\n", root->left->n, binary_tree_is_heap(root->left));

    node = binary_tree_node(root->right, 97);
    root->right->left = node;
    binary_tree_print(root);
    printf("Is %d heap: %d\n", root->n, binary_tree_is_heap(root));

    node = binary_tree_node(root->right, 79);
    root->right->right = node;
    binary_tree_print(root);
    printf("Is %d heap: %d\n", root->n, binary_tree_is_heap(root));

    return (0);
}

