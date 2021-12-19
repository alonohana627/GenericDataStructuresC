#include "doublylinkedlist.h"
#include <stdio.h>
#include <stdlib.h>

linkedlist *create_linkedlist()
{
    linkedlist *list = malloc(sizeof(linkedlist));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void linkedlist_add(linkedlist *list, void *data)
{
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = new_node;
    }
    list->size++;
}

void *linkedlist_get(linkedlist *list, int index)
{
    if (index < 0 || index >= list->size) {
        return NULL;
    }
    node *current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

node *linkedlist_get_head(linkedlist *list)
{
    return list->head;
}

node *linkedlist_get_tail(linkedlist *list)
{
    return list->tail;
}

node *linkedlist_find(linkedlist *list, void *data)
{
    node *current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void linkedlist_remove(linkedlist *list, int index)
{
    if (index < 0 || index >= list->size) {
        return;
    }
    node *current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        list->tail = current->prev;
    }
    free(current);
    list->size--;
}

void linkedlist_free(linkedlist *list)
{
    node *current = list->head;
    while (current != NULL) {
        node *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

// int main(){
//     linkedlist *list = create_linkedlist();
//     linkedlist_add(list, "Hello");
//     linkedlist_add(list, "World");
//     linkedlist_add(list, "!");
//     printf("%s\n", (char *)linkedlist_get(list, 0));
//     printf("%s\n", (char *)linkedlist_get(list, 1));
//     printf("%s\n", (char *)linkedlist_get(list, 2));
//     linkedlist_remove(list, 1);
//     printf("%s\n", (char *)linkedlist_get(list, 0));
//     printf("%s\n", (char *)linkedlist_get(list, 1));
//     linkedlist_free(list);

//     int a = 0;
//     int b = 1;
//     int c = 2;
//     int d = 3;
//     int e = 4;
//     int f = 5;
//     int g = 6;
//     int h = 7;
//     linkedlist *list2 = create_linkedlist();
//     linkedlist_add(list2, &a);
//     linkedlist_add(list2, &b);
//     linkedlist_add(list2, &c);
//     linkedlist_add(list2, &d);
//     linkedlist_add(list2, &e);
//     linkedlist_add(list2, &f);
//     linkedlist_add(list2, &g);
//     linkedlist_add(list2, &h);
//     printf("%d\n", *(int *)linkedlist_get(list2, 0));
//     printf("%d\n", *(int *)linkedlist_get(list2, 1));
//     printf("%d\n", *(int *)linkedlist_get(list2, 2));
//     printf("%d\n", *(int *)linkedlist_get(list2, 3));
//     printf("%d\n\n", *(int *)linkedlist_get(list2, 4));

//     int i = *(int *)linkedlist_get(list2, 2);
//     printf("%d\n", i);
//     linkedlist_remove(list2, 2);
//     i = *(int *)linkedlist_get(list2, 2);
//     i*=2;
//     printf("%d\n", i);
//     return 0;
// }