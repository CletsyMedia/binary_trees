#include "binary_trees.h"

/**
 * create_node - Creates a new level order queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
  levelorder_queue_t *newNode;

  newNode = malloc(sizeof(levelorder_queue_t));
  if (newNode == NULL)
    return (NULL);

  newNode->node = node;
  newNode->next = NULL;

  return (newNode);
}
