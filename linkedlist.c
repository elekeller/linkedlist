#include "linkedlist.h"
#include <assert.h>

void node_new(node *n, int allocsize, void *data) // data = malloc(size);
{
    assert(pthread_mutex_init(n->lock, NULL) == 0);
    n->data = malloc(allocsize);
    assert(n->data != NULL);

    for (int i = 0; i < allocsize; i++)
    {
        *((int *)n->data + i * sizeof(int)) = 0;
    }

    assert(pthread_mutex_lock(n->lock) == 0);
    assert(memcpy(n->data, data, allocsize) != NULL);
    assert(pthread_mutex_unlock(n->lock) == 0);
}

node *
node_del(node *n) // free(data); return next;
{
    node *p = n->next;
    free(n->data);
    return p;
}
void ll_init(linkedlist *l, int elementsize) // "Konstruktor"
{
    l->elementsize = elementsize;
    l->listsize = DEF_CAPACITY;
    l->head->prev = NULL;
    l->head->next = l->tail;
    l->tail->prev = l->head;
    l->tail->next = NULL;
    node_new(l->head, elementsize, NULL);
    node_new(l->tail, l->elementsize, NULL);
}
void ll_add(linkedlist *l, void *data) // node_new(new, l->elementsize); tail->prev->next = new; tail->prev = new;
{
    node *n;
    node_new(n, l->elementsize, data);
    // l->tail->prev->next = n;
    l->tail->prev = n;
    l->listsize++;
}
int ll_size(linkedlist *l) // return l->listsize;
{
    return l->listsize;
}
void ll_dispose(linkedlist *l) // free(all nodes)
{
    node *p = NULL;
    p = l->head;
    while (p != NULL)
    {
        p = node_del(p);
    }
}