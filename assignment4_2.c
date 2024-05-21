#include <stdio.h>
#include <stdlib.h>
struct queue{
	int front;
	int rear;
	int maxqsize;
	unsigned short count;
	int* elem;
};
struct queue* CreateIntegerQueue(int qsize){
	struct queue *q=(struct queue*)malloc(sizeof(struct queue));
	q->front=0;
	q->rear=-1;
	q->count=0;
	q->maxqsize=qsize;
	q->elem=(int*)malloc(sizeof(int)*qsize);
	return q;
}
int IsIntegerQueueFull(struct queue* q){
	if(q->count>=q->maxqsize){
		return 1;
	}
	else{
		return 0;
	}
}
int IsIntegerQueueEmpty(struct queue* q){
	if(q->count<=0){
		return 1;
	}
	else{
		return 0;
	}
}
int enqueueInteger(int d,struct queue* q){
	if(!IsIntegerQueueFull(q)){
		q->rear=(q->rear+1)%q->maxqsize;
		q->elem[q->rear]=d;
		q->count++;
		return 1;
	}
	else{
		return 0;
	}
}
int dequeueInteger(int *dp,struct queue* q){
	if(!IsIntegerQueueEmpty(q)){
		q->count--;
		*dp=q->elem[q->front];
		q->front=(q->front+1)%q->maxqsize;
		return 1;
	}
	else{
		return 0;
	}
}
int FreeIntegerQueue(struct queue* q){
	free(q);
	return 1;
}
int main(){
	int n;
	int rValue;
	//rValue=(rand()%10);
	printf("Enter the size of queue: ");
	scanf("%d",&n);
	struct queue* Myqueue=CreateIntegerQueue(n);
	for(int i=0;i<n;i++){
		unsigned int d;
		printf("Enter the integer that is enqueued: ");
		scanf("%d",&d);
		enqueueInteger(d,Myqueue);
	}
	while(!IsIntegerQueueEmpty(Myqueue)){
		int qElement;
		dequeueInteger(&qElement,Myqueue);
		if(qElement>0){
		    rValue=rand()%10+1;
	//	    printf("%d\n",rValue);
			qElement=qElement-rValue;
			enqueueInteger(qElement,Myqueue);
		}
		else{
			continue;
		}
	}
	printf("The final elements of queue after the process are :\n");
	printf("%d\n",Myqueue->count);
/*	for(int i=0;i<n;i++){
		int show;
		dequeueInteger(&show,Myqueue);
		printf("Element %d in Myqueue is %d\n",i+1,show);
	}*/
	return 0;
}
	
