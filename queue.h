#ifndef _QUEUE_H_
# define _QUEUE_H_

typedef struct		node
{
  void			*data;
  struct node		*next;
  struct node		*prev;
}			node;

typedef struct          queue
{
  // Properties
  unsigned int          len;
  struct node           *head;
  struct node		*end;

  // Methods
  void			(*push)(struct queue *th, void *data);
  void			(*pop)(struct queue *th);
  void			(*clear)(struct queue *th);
  unsigned int		(*size)(struct queue *th);
  unsigned int		(*empty)(struct queue *th);
  void *		(*front)(struct queue *th);
  void *		(*swap)(struct queue *th, struct queue *to_swap);
  void			(*view)(struct queue *th, void (*display)(void *data));
}			queue;

struct queue *		new_queue(void);
void			queue_init(struct queue *th);
void			queue_destroy(struct queue *th);

#endif // _QUEUE_H_
