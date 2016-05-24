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

  printf("test1:\n");
  for (i = 0; i < 7; ++i)
    queue->push(queue, &tab[i]);
  queue->view(queue, &show);
  printf("size: 7:%d\n", queue->size(queue));
  printf("empty: 0:%d\n", queue->empty(queue));
  printf("top: %d\n", *(int *)(queue->front(queue)));
  printf("----------\n\n");

  printf("test2:\n");
  queue->pop(queue);
  queue->view(queue, &show);
  printf("size: 6:%d\n", queue->size(queue));
  printf("empty: 0:%d\n", queue->empty(queue));
  printf("top: %d\n", *(int *)(queue->front(queue)));
  printf("----------\n\n");

  printf("test3:\n");
  for (i = 0; i < 3; i++)
    queue->pop(queue);
  queue->view(queue, &show);
  printf("size: 3:%d\n", queue->size(queue));
  printf("empty: 0:%d\n", queue->empty(queue));
  printf("top: %d\n", *(int *)(queue->front(queue)));
  printf("----------\n\n");

  printf("test4:\n");
  for (i = 0; i < 20; i++)
    queue->pop(queue);
  printf("size: 0:%d\n", queue->size(queue));
  printf("empty: 1:%d\n", queue->empty(queue));
  printf("----------\n\n");

  printf("test5:\n");
  for (i = 0; i < 7; ++i)
    queue->push(queue, &tab[i]);
  queue->view(queue, &show);
  printf("size: 7:%d\n", queue->size(queue));
  printf("empty: 0:%d\n", queue->empty(queue));
  printf("----------\n\n");

  printf("test6:\n");
  queue->clear(queue);
  printf("size: 0:%d\n", queue->size(queue));
  printf("empty: 1:%d\n", queue->empty(queue));
  printf("----------\n\n");

  queue_destroy(queue);

  printf("test7:\n");
  queue->view(queue, &show);
  printf("size: 0:%d\n", queue->size(queue));
  printf("empty: 1:%d\n", queue->empty(queue));
  printf("----------\n\n");

  queue_destroy(queue);

  free(queue);

  return (0);
}
