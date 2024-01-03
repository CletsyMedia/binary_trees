#ifndef _BINARY_TREES_H
#define _BINARY_TREES_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Data structures */

/**
 * struct binary_tree_s - Binary tree node
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/**
 * struct levelorder_queue_s - Level order traversal queue.
 * @node: A node of a binary tree.
 * @next: The next node to traverse to in the binary tree.
 */
typedef struct levelorder_queue_s
{
	binary_tree_t *node;
	struct levelorder_queue_s *next;
} levelorder_queue_t;

/* Printing helper function */
void binary_tree_print(const binary_tree_t *);

/* Prototypes for all the functions */

/* Create a new binary tree node with a given parent and value */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* Insert a new node as the left child of the given parent node */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* Insert a new node as the right child of the given parent node */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* Delete an entire binary tree, freeing up memory */
void binary_tree_delete(binary_tree_t *tree);

/* Check if a node is a leaf in the binary tree */
int binary_tree_is_leaf(const binary_tree_t *node);

/* Check if a node is the root of the binary tree */
int binary_tree_is_root(const binary_tree_t *node);

/* Traverse the tree in pre-order and apply a function to each node's value */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/* Traverse the tree in-order and apply a function to each node's value */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

/* Traverse the tree post-order and apply a function to each node's value */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/* Calculate the height of the binary tree */
size_t binary_tree_height(const binary_tree_t *tree);

/* Calculate the depth of a specific node in the binary tree */
size_t binary_tree_depth(const binary_tree_t *tree);

/* Calculate the total number of nodes in the binary tree */
size_t binary_tree_size(const binary_tree_t *tree);

/* Calculate the number of leaf nodes in the binary tree */
size_t binary_tree_leaves(const binary_tree_t *tree);

/* Calculate the number of non-leaf nodes in the binary tree */
size_t binary_tree_nodes(const binary_tree_t *tree);

/* Check the balance factor of the binary tree */
int binary_tree_balance(const binary_tree_t *tree);

/* Check if the binary tree is a full binary tree */
int binary_tree_is_full(const binary_tree_t *tree);

/* Check if the binary tree is a perfect binary tree */
int binary_tree_is_perfect(const binary_tree_t *tree);

/* Get the sibling of a given node in the binary tree */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);

/* Get the uncle of a given node in the binary tree */
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

/* Find the lowest common ancestor of two nodes in the binary tree */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);

/* levelorder Binary tree struct */
/**
 * struct node_s - singly linked list
 * @node: const binary tree node
 * @next: points to the next node
 */
typedef struct node_s
{
	const binary_tree_t *node;
	struct node_s *next;
} ll;
/* More levelorder functions */
levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
							 levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
void push(binary_tree_t *node, levelorder_queue_t *head,
					levelorder_queue_t **tail);

/* B-tree remove */
bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);
/* B-tree remove end */

/* Advancing on the project*/

/* Perform level-order traversal and apply a function to each node's value */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/* Check if the binary tree is a complete binary tree */
int binary_tree_is_complete(const binary_tree_t *tree);

/* Rotate the binary tree to the left */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);

/* Rotate the binary tree to the right */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

/* Check if the binary tree is a binary search tree (BST) */
int binary_tree_is_bst(const binary_tree_t *tree);

/* Insert a value into a binary search tree (BST) */
bst_t *bst_insert(bst_t **tree, int value);

/* Convert an array to a binary search tree (BST) */
bst_t *array_to_bst(int *array, size_t size);

/* Search for a value in a binary search tree (BST) */
bst_t *bst_search(const bst_t *tree, int value);

/* Remove a value from a binary search tree (BST) */
bst_t *bst_remove(bst_t *root, int value);

/* Check if the binary tree is an AVL tree */
int binary_tree_is_avl(const binary_tree_t *tree);

/* Insert a value into an AVL tree */
avl_t *avl_insert(avl_t **tree, int value);

/* Convert an array to an AVL tree */
avl_t *array_to_avl(int *array, size_t size);

/* Remove a value from an AVL tree */
avl_t *avl_remove(avl_t *root, int value);

/* Convert a sorted array to an AVL tree */
avl_t *sorted_array_to_avl(int *array, size_t size);

/* Check if the binary tree is a binary heap */
int binary_tree_is_heap(const binary_tree_t *tree);

/* Insert a value into a binary heap */
heap_t *heap_insert(heap_t **root, int value);

/* Convert an array to a binary heap */
heap_t *array_to_heap(int *array, size_t size);

/* Extract the root value from a binary heap */
int heap_extract(heap_t **root);

/* Convert a binary heap to a sorted array */
int *heap_to_sorted_array(heap_t *heap, size_t *size);

#endif /* _BINARY_TREES_H */
