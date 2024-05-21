#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int *arr;
};

void init(struct queue *q1){
  q1->size = 0;
  q1->front = -1;
  q1->rear = -1;
}

struct queue createIntegerQueue(int queSize){
    if (queSize <= 0){
    struct queue q3;
    init(&q3);
    q3.size = queSize;
    return q3;
    }
    
    struct queue q2;
    init(&q2);
    q2.arr = (int *)malloc(queSize * sizeof(int));
    q2.size = queSize;
    return q2;
}

int isIntegerQueueFull(struct queue *q){
    if(q->rear == q->size-1){
        return 1;
    }

    return 0;
}

int isIntegerQueueEmpty(struct queue *q){
    if (q->front == q->rear){
        return 1;
    }

    return 0;
}

int enqueueInteger(struct queue *q, int d){
    if (q->rear == q->size-1)
    {
        return 0;
    }

    q->rear++;
    q->arr[q->rear] = d;
    return 1;
}

int dequeueInteger(struct queue *q, int *dp){
    if (q->front == q->rear){
        return 0;
    }

    q->front++;
    *dp = q->arr[q->front];
    return 1;
}

int freeIntegerQueue(struct queue *q){
  
    free(q);
    return 1;
}

int main(){
  struct queue q1;
  int c, l; //c is choice number and l is size of queue
  int elem, ele, check;
  init(&q1);
  while (1){
    printf("\nEnter the following choices for the desired opreations to be done\n ");
    printf("1. Create an Integer queue \n ");
    printf("2. Enqueuing Element to Queue \n ");
    printf("3. dequeuing Element to Queue \n ");
    printf("4. Free the queue \n ");
    printf("5. Check if queue is full \n ");
    printf("6. Check whether the queue is empty\n ");
    printf("Press 0 to terminate the process");
    scanf("%d", &c);

    if (c == 1){
      printf("\nEnter the size of the queue:\n");
      scanf("%d", &l);
      q1 = createIntegerQueue(l);

      if (q1.size <= 0){
        printf("\nOperation is not successful\n");
      }else{
        printf("\nOperation is successful\n");
      }
      continue;
    }
    else if (c == 2)
    {
      printf("\nEnter the element to be enqueued:\n");
      scanf("%d", &elem);
      check = enqueueInteger(&q1, elem);
      if (check){
        printf("\nOperation is successful\n");
      }else{
        printf("\nOperation is not successful\n");
      }
      continue;
    }
    else if (c == 3)
    {
      printf("Dequeing Element from the queue\n");  
      check = dequeueInteger(&q1, &ele);
      if (check){
        printf("\nOperation is successful\n");
        printf("\nThe deque element is %d\n", ele);
      }else{
        printf("\nOperation is not successful\n");
      }
      continue;
    }
    else if (c == 4)
    {
      check = freeIntegerQueue(&q1);
      if (check){
        printf("\nOperation is successful\n");
      }else{
        printf("\nOperation is not successful\n");
      }
      continue;
    }
    else if (c == 5)
    {
      check = isIntegerQueueFull(&q1);
      if (q1.size <= 0){
        printf("Queue is not Created\n");
        continue;
      }

      if (check){
        printf("\nThe Queue is full\n");
      }else{
        printf("\nThe Queue is not full\n");
      }
      continue;
    }
    else if (c == 6)
    {
      check = isIntegerQueueEmpty(&q1);
      if (q1.size <= 0){
        printf("Queue is not created\n");
        continue;
      }
      if (check){
        printf("\nQueue is empty\n");
      }
      else{
        printf("\nQueue is not empty\n");
      }
      continue;
    }
    else if (c == 0){
      break;
    }
    else{
      printf("\nInvalid choice try again\n");
      continue;
    }
  }
  return 0;
}