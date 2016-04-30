#ifndef _QUEUE_H_
# define _QUEUE_H_

typedef struct		node
{
  void			*data;
  struct node		*next;
}			node;

typedef struct          queue
{
  // Properties
  unsigned int          len;
  struct node           *head;

  // Methods
  void			(*enqueue)(struct queue *th, void *data);
  void *		(*dequeue)(struct queue *th);
  void			(*clear)(struct queue *th);
  unsigned int		(*size)(struct queue *th);
  unsigned int		(*is_empty)(struct queue *th);
  void			(*view)(struct queue *th, void (*display)(void *data));
}			queue;

struct queue *		new_queue(void);
void			queue_init(struct queue *th);
void			queue_destroy(struct queue *th);

#endif // _QUEUE_H_
