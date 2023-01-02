#include "linkedlist.h"
#include <assert.h>

int node_new(node *n, int allocsize, void *data); // data = malloc(size);
{
    int r = 1;
    assert(pthread_mutex_init(n->lock) == 0);
    n->data = malloc(allocsize);
    assert(n->data != NULL);
    assert(pthread_mutex_lock(n->lock) == 0);
    assert(memcpy(n->data, data, allocsize) == allocsize);
    assert(pthread_mutex_unlock(n->lock) == 0);
    r = 0;
    return r;
}

node *
node_del(node *); // free(data); return next;
{
    ;
}
void ll_init(linkedlist *, int); // "Konstruktor"
{
    ;
}
int ll_add(linkedlist *l, void *data); // node_new(new, l->elementsize); tail->prev->next = new; tail->prev = new;
{
    node *n;
    int r = node_new(n, l->elementsize, data);
    l->tail->prev->next = n;
    l->tail->prev = n;
    l->listsize++;
    return r;
}
int ll_size(linkedlist *l); // return l->listsize;
{
    return l->listsize;
}
void ll_dispose(linkedlist *); // free(all nodes)
{
    ;
}