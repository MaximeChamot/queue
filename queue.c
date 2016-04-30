#include <stdlib.h>
#include "queue.h"

// Public methods declaration
static void		enqueue(struct queue *th, void *data);
static void *		dequeue(struct queue *th);
static void		clear(struct queue *th);
static unsigned int	size(struct queue *th);
static unsigned int	is_empty(struct queue *th);
static void		view(struct queue *th, void (*display)(void *data));

// Private functions declaration
static void             init_method_ptr(struct queue *th);
static struct node *	get_last_node(struct node *head);
static void *		delete_node(struct queue *th);

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
    }
}

// Public methods
static void		enqueue(struct queue *th, void *data)
{
  struct node		*new_node = NULL;
  struct node		*last_node = NULL;

  if (th != NULL)
    {
      if ((new_node = (struct node *)malloc(sizeof(struct node))) != NULL)
	{
	  new_node->data = data;
	  new_node->next = NULL;
	  if (th->head != NULL)
	    {
	      last_node = get_last_node(th->head);
	      last_node->next = new_node;
	    }
	  else
	    th->head = new_node;
	  th->len++;
	}
    }
}

static void *		dequeue(struct queue *th)
{
  if (th != NULL && th->head != NULL)
    return (delete_node(th));
  return (NULL);
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

static unsigned int	is_empty(struct queue *th)
{
  if (th != NULL && th->head != NULL && th->len > 0)
    return (0);
  return (1);
}

static void		view(struct queue *th, void (*display)(void *data))
{
  struct node		*node = NULL;

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
      th->enqueue = &enqueue;
      th->dequeue = &dequeue;
      th->clear = &clear;
      th->size = &size;
      th->is_empty = &is_empty;
      th->view = &view;
    }
}

static struct node *	get_last_node(struct node *head)
{
  struct node		*node = NULL;

  if (head != NULL)
    {
      node = head;
      while (node->next != NULL)
	node = node->next;
      return (node);
    }
  return (NULL);
}

static void *		delete_node(struct queue *th)
{
  struct node		*tmp = NULL;
  void			*data = NULL;

  if (th != NULL)
    {
      tmp = th->head;
      data = tmp->data;
      th->head = tmp->next;
      free(tmp);
      th->len--;
    }
  return (data);
}
