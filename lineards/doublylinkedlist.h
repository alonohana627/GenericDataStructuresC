//Generic Doubly Linked List
//TODO: add comments
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

typedef struct node {
    void *data;
    struct node *next;
    struct node *prev;
} node;

typedef struct linkedlist {
    node *head;
    node *tail;
    int size;
} linkedlist;

linkedlist *create_linkedlist();
void linkedlist_add(linkedlist *list, void *data);
void *linkedlist_get(linkedlist *list, int index);
node *linkedlist_get_head(linkedlist *list);
node *linkedlist_get_tail(linkedlist *list);
node *linkedlist_find(linkedlist *list, void *data);
void linkedlist_remove(linkedlist *list, int index);
void linkedlist_free(linkedlist *list);

#endif