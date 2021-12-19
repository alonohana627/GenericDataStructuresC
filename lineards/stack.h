// GENERIC STACK HEADER
// TODO: add description
#ifndef STACK_H
#define STACK_H

/**
 * @brief Generic stack data structure
 * Memory allocates for the stack is done by the user.
 */
typedef struct stack_t {
    void *data;
    struct stack_t *next;
} stack_t;

/**
 * @brief Push data to the stack
 * 
 * @param stack Pointer to the stack
 * @param data Pointer to the data to be pushed
 */
void stack_push(stack_t **stack, void *data);

/**
 * @brief Pop data from the stack
 * 
 * @param stack Pointer to the stack
 * @return void* Pointer to the data popped
 */
void *stack_pop(stack_t **stack);

/**
 * @brief Peek at the top of the stack
 * 
 * @param stack Pointer to the stack
 * @return void* Pointer to the data at the top of the stack
 */
void *stack_peek(stack_t *stack);

/**
 * @brief Free the stack
 * 
 * @param stack Pointer to the stack
 */
void stack_free(stack_t **stack);

#endif