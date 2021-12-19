#include "AVLtree.h"
#include <stdlib.h>
#include <stdio.h>

avltree *avltree_init(comparison_function comp)
{
    avltree *tree = (avltree*)malloc(sizeof(avltree));
    tree->root = NULL;
    tree->comp = comp;
    return tree;
}

void avltree_insert(avltree *tree, void *data)
{
    avltree_node *new_node = malloc(sizeof(avltree_node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;
    new_node->height = 1;
    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        avltree_node *current = tree->root;
        while (current != NULL) {
            int comp_result = tree->comp(data, current->data);
            if (comp_result < 0) {
                if (current->left == NULL) {
                    current->left = new_node;
                    new_node->parent = current;
                    break;
                } else {
                    current = current->left;
                }
            } else if (comp_result > 0) {
                if (current->right == NULL) {
                    current->right = new_node;
                    new_node->parent = current;
                    break;
                } else {
                    current = current->right;
                }
            } else {
                free(new_node);
                return;
            }
        }
    }
    avltree_rebalance(tree, new_node);
}

void avltree_remove(avltree *tree, void *data){
    avltree_node *node = avltree_find(tree, data);
    if (node == NULL) {
        return;
    }
    avltree_node *child;
    if (node->left == NULL) {
        child = node->right;
    } else if (node->right == NULL) {
        child = node->left;
    } else {
        avltree_node *next = node->right;
        while (next->left != NULL) {
            next = next->left;
        }
        child = next->right;
        if (next->parent == node) {
            next->parent = node->parent;
        } else {
            avltree_node *parent = next->parent;
            parent->left = next->right;
            next->right = node->right;
            next->parent = node->parent;
            next->right->parent = next;
        }
        if (node->parent == NULL) {
            tree->root = next;
        } else {
            avltree_node *parent = node->parent;
            if (parent->left == node) {
                parent->left = next;
            } else {
                parent->right = next;
            }
        }
    }
    if (child != NULL) {
        child->parent = node->parent;
    }
    if (node->parent == NULL) {
        tree->root = child;
    } else {
        avltree_node *parent = node->parent;
        if (parent->left == node) {
            parent->left = child;
        } else {
            parent->right = child;
        }
    }
    avltree_rebalance(tree, child);
    free(node);
}

void *avltree_find(avltree *tree, void *data)
{
    avltree_node *current = tree->root;
    while (current != NULL) {
        int comp_result = tree->comp(data, current->data);
        if (comp_result < 0) {
            current = current->left;
        } else if (comp_result > 0) {
            current = current->right;
        } else {
            return current->data;
        }
    }
    return NULL;
}

void avltree_rebalance(avltree *tree, avltree_node *node)
{
    while (node != NULL) {
        avltree_node *parent = node->parent;
        if (parent != NULL) {
            if (parent->left == node) {
                parent->height--;
            } else {
                parent->height++;
            }
        }
        if (node->height == -2) {
            if (node->left->height == -1) {
                avltree_rotate_right(tree, node);
            } else {
                avltree_rotate_left(tree, node->left);
                avltree_rotate_right(tree, node);
            }
        } else if (node->height == 2) {
            if (node->right->height == 1) {
                avltree_rotate_left(tree, node);
            } else {
                avltree_rotate_right(tree, node->right);
                avltree_rotate_left(tree, node);
            }
        }
        node = parent;
    }
}

void avltree_rotate_left(avltree *tree, avltree_node *node)
{
    avltree_node *parent = node->parent;
    avltree_node *right = node->right;
    avltree_node *right_left = right->left;
    if (parent != NULL) {
        if (parent->left == node) {
            parent->left = right;
        } else {
            parent->right = right;
        }
    } else {
        tree->root = right;
    }
    right->parent = parent;
    right->left = node;
    node->parent = right;
    node->right = right_left;
    if (right_left != NULL) {
        right_left->parent = node;
    }
    node->height = 1;
    right->height = 0;
}

void avltree_rotate_right(avltree *tree, avltree_node *node)
{
    avltree_node *parent = node->parent;
    avltree_node *left = node->left;
    avltree_node *left_right = left->right;
    if (parent != NULL) {
        if (parent->left == node) {
            parent->left = left;
        } else {
            parent->right = left;
        }
    } else {
        tree->root = left;
    }
    left->parent = parent;
    left->right = node;
    node->parent = left;
    node->left = left_right;
    if (left_right != NULL) {
        left_right->parent = node;
    }
    node->height = 1;
    left->height = 0;
}

void avltree_destroy(avltree *tree)
{
    avltree_node *current = tree->root;
    while (current != NULL) {
        avltree_node *next = current->left;
        if (next == NULL) {
            next = current->right;
        }
        free(current);
        current = next;
    }
    free(tree);
}

void avltree_print(avltree *tree, void (*print)(void *))
{
    avltree_node *current = tree->root;
    while (current != NULL) {
        if (current->left != NULL) {
            current = current->left;
        } else {
            print(current->data);
            current = current->right;
        }
    }
}

void avltree_print_inorder(avltree *tree, void (*print)(void *))
{
    avltree_node *current = tree->root;
    avltree_internal_print_inorder(current, print);
}

void avltree_internal_print_inorder(avltree_node *node, void (*print)(void *))
{
    if (node == NULL) {
        return;
    }
    avltree_internal_print_inorder(node->left, print);
    print(node->data);
    avltree_internal_print_inorder(node->right, print);
}


//Test
/*
int comp_int(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

void print_int(void *data)
{
    printf("%d ", *(int *)data);
}

int main(){
    avltree *tree = avltree_init(comp_int);
    int f = 6;
    int g = 7;
    int a = 1;
    int d = 4;
    int e = 5;
    int h = 8;
    int b = 2;
    int c = 3;

    avltree_insert(tree, &a);
    avltree_insert(tree, &b);
    avltree_insert(tree, &c);
    avltree_insert(tree, &d);
    avltree_insert(tree, &e);
    avltree_insert(tree, &f);
    avltree_insert(tree, &g);
    avltree_insert(tree, &h);

    avltree_print_inorder(tree, print_int);
    printf("\n");
    avltree_destroy(tree);
    return 0;
} */