#include <stdlib.h>
#include "queue.h"

// Public methods declaration
static void		push(struct queue *th, void *data);
static void		pop(struct queue *th);
static void		clear(struct queue *th);
static unsigned int	size(struct queue *th);
static unsigned int	empty(struct queue *th);
static void *		front(struct queue *th);
static void		view(struct queue *th, void (*display)(void *data));

// Private functions declaration
static void             init_method_ptr(struct queue *th);
static void		delete_node(struct queue *th);

// Constructor
struct queue *		new_queue(void)
{
  struct queue		*queue = NULL;

  if ((queue = (struct queue *)malloc(sizeof(struct queue))) != NULL)
    queue_init(queue);
  return (queue);
}

void			queue_init(struct queue *th)
{
  if (th != NULL)
    {
      th->len = 0;
      th->head = NULL;
      th->end = NULL;
      init_method_ptr(th);
    }
}

// Destructor
void			queue_destroy(struct queue *th)
{
  if (th != NULL)
    {
      th->clear(th);
      th->len = 0;
      th->head = NULL;
      th->end = NULL;
    }
}

// Public methods
static void		push(struct queue *th, void *data)
{
  struct node		*new_node;

  if (th != NULL && (new_node = (struct node *)malloc(sizeof(struct node))) != NULL)
    {
      new_node->data = data;
      new_node->next = NULL;
      new_node->prev = NULL;
      if (th->head != NULL)
	{
	  new_node->next = th->head;
	  th->head->prev = new_node;
	}
      th->head = new_node;
      th->len++;
    }
}

static void		pop(struct queue *th)
{
  if (th != NULL && th->head != NULL)
    delete_node(th);
}

static void		clear(struct queue *th)
{
  if (th != NULL && th->head != NULL)
    {
      while (th->head != NULL)
	delete_node(th);
    }
}

static unsigned int	size(struct queue *th)
{
  if (th != NULL)
    return (th->len);
  return (0);
}

static unsigned int	empty(struct queue *th)
{
  if (th != NULL && th->head != NULL && th->len > 0)
    return (0);
  return (1);
}

static void *		front(struct queue *th)
{
  if (th != NULL && th->head != NULL)
    return (th->head->data);
  return (NULL);
}

static void		view(struct queue *th, void (*display)(void *data))
{
  struct node		*node;

  if (th != NULL && display != NULL)
    {
      node = th->head;
      while (node)
	{
	  display(node->data);
	  node = node->next;
	}
    }
}

// Private functions
static void             init_method_ptr(struct queue *th)
{
  if (th != NULL)
    {
      th->push = &push;
      th->pop = &pop;
      th->clear = &clear;
      th->size = &size;
      th->empty = &empty;
      th->front = &front;
      th->view = &view;
    }
}

static void		delete_node(struct queue *th)
{
  struct node		*tmp;

  if (th != NULL && th->head != NULL)
    {
      tmp = th->head;
      th->head = th->head->next;
      free(tmp);
      th->len--;
    }
}
