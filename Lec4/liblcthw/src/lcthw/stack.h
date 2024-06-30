#ifndef lcthw_Stack_h
#define lcthw_Stack_h

#include <lcthw/list.h>

typedef List Stack;

Stack *Stack_create()
{
    return List_create();
}

void Stack_destroy(Stack *stack)
{
    List_destroy(stack);
}

void Stack_push(Stack *stack, void *value)
{
    List_push(stack, value);
}

void *Stack_pop(Stack *stack)
{
    return List_pop(stack);
}

void *Stack_peek(Stack *stack)
{
    return stack->last->value;
}

int Stack_count(Stack *stack)
{
    return stack->count;
}

#define STACK_FOREACH(S, C) ListNode *C = NULL;\
    for(C = S->last; C != NULL; C = C->prev)


#endif