#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void		show(void *data)
{
  unsigned int *nbr = (int *)(data);
  printf("data: %d\n", *nbr);
}

int		main()
{
  queue		*queue;
  int		tab[] = { 10, 15, 20, 25, 30, 1, 2 };
  int		i;

  queue = new_queue();

  for (i = 0; i < 7; ++i)
    queue->enqueue(queue, &tab[i]);
  queue->view(queue, &show);
  printf("size: 7:%d\n", queue->size(queue));

  printf("----------\n");
  queue->dequeue(queue);
  queue->view(queue, &show);
  printf("size: 6:%d\n", queue->size(queue));

  printf("----------\n");
  queue->dequeue(queue);
  queue->dequeue(queue);
  queue->dequeue(queue);
  queue->view(queue, &show);
  printf("size: 3:%d\n", queue->size(queue));

  printf("----------\n");
  queue->dequeue(queue);
  queue->dequeue(queue);
  queue->dequeue(queue);
  queue->dequeue(queue);
  queue->dequeue(queue);
  queue->dequeue(queue);
  queue->dequeue(queue);
  queue->dequeue(queue);
  queue->dequeue(queue);
  queue->view(queue, &show);
  printf("size: 0:%d\n", queue->size(queue));

  printf("----------\n");
  for (i = 0; i < 7; ++i)
    queue->enqueue(queue, &tab[i]);
  queue->view(queue, &show);
  printf("size: 7:%d\n", queue->size(queue));

  printf("----------\n");
  queue_destroy(queue);
  queue->view(queue, &show);
  printf("size: 0:%d\n", queue->size(queue));

  queue_destroy(queue);
  free(queue);
  return (0);
}
