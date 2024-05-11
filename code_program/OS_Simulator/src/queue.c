#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) 
{
        if (q == NULL) return 1;
        return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
        /* TODO: put a new process to queue [q] */
        if(q->size < MAX_QUEUE_SIZE)
        {
                q->proc[(q->cursor + q->size) % MAX_QUEUE_SIZE] = proc;
                q->size++;
        }
        else
        {
                printf("FULL QUEUE");
        }
}

struct pcb_t * dequeue(struct queue_t * q) {
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
        if(q->size <= 0) return NULL;
        else
        {
                // How can we know that this is the last element
                // cursor = (cursor + size) % MAX_SIZE_SLOT;
                struct pcb_t* proc = q->proc[q->cursor];
                q->cursor = (q->cursor + 1) % MAX_QUEUE_SIZE;
                q->size--;
                q->timeslot--;
                return proc;
        }
}

