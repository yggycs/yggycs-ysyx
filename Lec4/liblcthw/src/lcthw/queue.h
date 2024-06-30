#ifndef lcthw_Stack_h
#define lcthw_Stack_h

#include <lcthw/list.h>

typedef List Queue;

Queue *Queue_create()
{
    return List_create();
}

void Queue_destroy(Queue *queue)
{
    List_destroy(queue);
}

void Queue_send(Queue *queue, void *value)
{
    List_push(queue, value);
}

void *Queue_recv(Queue *queue)
{
    return List_shift(queue);
}

void *Queue_peek(Queue *queue)
{
    return queue->first->value;
}

int Queue_count(Queue *queue)
{
    return queue->count;
}

#define QUEUE_FOREACH(S, C) ListNode *C = NULL;\
    for(C = S->first; C != NULL; C = C->next)

#endif