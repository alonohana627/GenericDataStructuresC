//GENERIC QUEUE HEADER
// TODO: add description
#ifndef QUEUE_H
#define QUEUE_H

/**
 * @brief Generic queue data structure
 * Memory allocates for the queue is done by the user.
 */
typedef struct queue_t {
    void *data;
    struct queue_t *next;
} queue_t;

/**
 * @brief Push data to the queue
 * 
 * @param queue Pointer to the queue
 * @param data Pointer to the data to be pushed
 */
void queue_push(queue_t **queue, void *data);

/**
 * @brief Pop data from the queue
 * 
 * @param queue Pointer to the queue
 * @return void* Pointer to the data popped
 */
void *queue_pop(queue_t **queue);

/**
 * @brief Peek at the top of the queue
 * 
 * @param queue Pointer to the queue
 * @return void* Pointer to the data at the top of the queue
 */
void *queue_peek(queue_t *queue);

/**
 * @brief Free the queue
 * 
 * @param queue 
 */
void queue_free(queue_t **queue);

#endif