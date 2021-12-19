#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void queue_push(queue_t **queue, void *data)
{
    queue_t *new_node = malloc(sizeof(queue_t));
    new_node->data = data;
    new_node->next = NULL;
    if(*queue == NULL)
    {
        *queue = new_node;
    }
    else
    {
        queue_t *temp = *queue;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void *queue_pop(queue_t **queue)
{
    if(*queue == NULL)
    {
        return NULL;
    }
    queue_t *temp = *queue;
    *queue = (*queue)->next;
    void *data = temp->data;
    free(temp);
    return data;
}

void *queue_peek(queue_t *queue)
{
    if(queue == NULL)
    {
        return NULL;
    }
    return queue->data;
}

void queue_free(queue_t **queue)
{
    while(*queue != NULL)
    {
        queue_pop(queue);
    }
}

int main()
{
    queue_t *queue = NULL;
    queue_push(&queue, "Hello");
    queue_push(&queue, "World");
    printf("%s\n", (char *)queue_pop(&queue));
    printf("%s\n", (char *)queue_pop(&queue));
    queue_free(&queue);
    return 0;
}