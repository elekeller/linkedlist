#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <pthread.h>

/**
 * @brief node points to data, next, prev and a lock
 */

typedef struct _node_
{
    pthread_mutex_t *lock;
    struct node *prev;
    struct node *next;
    void *data;
} node;

void node_new(node *, int, void *); // data = malloc(size);

node *node_del(node *); // free(data); return next;

/**
 * @brief linkedlist stores nodes
 * head is the first node
 * tail is the last
 */

typedef struct
{
    node *head;
    node *tail;
    int listsize;
    int elementsize;
} linkedlist;

void ll_init(linkedlist *, int); // "Konstruktor"

int ll_add(linkedlist *, void *); // node_new(new, l->elementsize); tail->prev->next = new; tail->prev = new;

int ll_size(linkedlist *); // return l->listsize;

void ll_dispose(linkedlist *); // free(all nodes)

//

#endif