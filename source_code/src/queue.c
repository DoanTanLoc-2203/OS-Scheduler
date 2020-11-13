#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */
	if (q->size == MAX_QUEUE_SIZE) return;
	else {
		q->proc[q->size++] = proc;
	}	
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (q->size == 0 ) return NULL;
	int idx = 0 , j = 1;
	int max_priority= q->proc[0]->priority;
	for (j = 1; j<q->size; j++){
		if (q->proc[j]->priority > max_priority){
			idx = j;
			max_priority=q->proc[j]->priority;
		}
	}
	struct pcb_t *out = q->proc[idx];
	for (j = idx+1;j< q->size; j++){
		q->proc[j-1] = q->proc[j];
	}
	q->size--;
	return out;
}

