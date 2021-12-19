// Generic AVL Tree
/** AVL Tree Explanation
 *  AVL Tree is a self balancing binary search tree.
 * It is a self balancing binary search tree because it is a binary search tree
 * and it is a self balancing binary search tree because it is a binary search tree.
 * 
 * The way AVL Tree balances itself is by rotating the tree to the left or right
 * depending on the balance factor.
 * 
 * The balance factor is the difference in height of the left and right subtrees.
 * 
 * Example:
 *      [4]
 *      /  \
 *    [2]   [6]
 *   / \    / \
 * [1] [3] [5] [7]
 * 
 * Such tree concides balanced.
 * 
 */
#ifndef AVLTREE_H
#define AVLTREE_H

/**
 * @brief compare function for avltree
 * @param a first value to compare
 * @param b second value to compare
 * @return 0 if a == b, -1 if a < b, 1 if a > b
 * @note this function must be defined by the user
 */
typedef int (*comparison_function)(void*, void*);

/**
 * @brief avltree node
 * @note this struct is not meant to be used by the user
 */
typedef struct avltree_node {
    void *data;
    struct avltree_node *left;
    struct avltree_node *right;
    struct avltree_node *parent;
    int height;
} avltree_node;

/**
 * @brief avltree
 */
typedef struct avltree {
    avltree_node *root;
    comparison_function comp;
} avltree;

/**
 * @brief create an avltree
 * 
 * @param comp comparison function
 * @return avltree* pointer to the new avltree
 */
avltree *avltree_init(comparison_function comp);

/**
 * @brief insert a value into the avltree
 * 
 * @param tree avltree to insert into
 * @param data value to insert
 */
void avltree_insert(avltree *tree, void *data);

/**
 * @brief remove a value from the avltree
 * 
 * @param tree avltree to remove from
 * @param data value to remove
 */
void avltree_remove(avltree *tree, void *data);

/**
 * @brief find a value in the avltree
 * 
 * @param tree avltree to search in
 * @param data value to search for
 * @return void* pointer to the value if found, NULL otherwise
 * @note this function returns the first value found, not necessarily the one
 *      with the lowest value
 */
void *avltree_find(avltree *tree, void *data);

/**
 * @brief rebalance the avltree
 * 
 * @param tree avltree to rebalance
 * @param node node to rebalance
 * @note this function is not meant to be used by the user
 */
void avltree_rebalance(avltree *tree, avltree_node *node);

/**
 * @brief rotate the avltree to the left
 * 
 * @param tree avltree to rotate
 * @param node node to rotate
 */
void avltree_rotate_left(avltree *tree, avltree_node *node);

/**
 * @brief rotate the avltree to the right
 * 
 * @param tree avltree to rotate
 * @param node node to rotate
 */
void avltree_rotate_right(avltree *tree, avltree_node *node);

/**
 * @brief print the avltree from smaller to bigger
 * 
 * @param tree avltree to print
 * @param print function to print the value
 */
void avltree_print_inorder(avltree *tree, void (*print)(void *));

/**
 * @note this function is not meant to be used by the user
 */
void avltree_internal_print_inorder(avltree_node *node, void (*print)(void *));

/**
 * @brief free the avltree
 * 
 * @param tree avltree to free
 */
void avltree_destroy(avltree *tree);

#endif