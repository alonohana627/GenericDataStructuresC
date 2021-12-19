#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void stack_push(stack_t **stack, void *data)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    new_node->data = data;
    new_node->next = *stack;
    *stack = new_node;
}

void *stack_pop(stack_t **stack)
{
    if(*stack == NULL)
    {
        return NULL;
    }
    stack_t *temp = *stack;
    *stack = (*stack)->next;
    void *data = temp->data;
    free(temp);
    return data;
}

void *stack_peek(stack_t *stack)
{
    if(stack == NULL)
    {
        return NULL;
    }
    return stack->data;
}

void stack_free(stack_t **stack)
{
    while(*stack != NULL)
    {
        stack_pop(stack);
    }
}

// Stack Basic Test

// int main(){
//     stack_t *stack = NULL;
//     stack_push(&stack, "Hello");
//     stack_push(&stack, "World");
//     printf("%s\n", (char *)stack_pop(&stack));
//     printf("%s\n", (char *)stack_pop(&stack));
//     stack_free(&stack);

//     stack_t *stack2 = NULL;
//     stack_push(&stack2, 123);
//     stack_push(&stack2, 456);
//     printf("%d\n", (int)stack_pop(&stack2));
//     printf("%d\n", (int)stack_pop(&stack2));
//     stack_free(&stack2);

//     return 0;
// }