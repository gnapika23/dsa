#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
 int top;
 int *space;
 int size;
}stack;

int isEmpty(stack *s){
 if(s->top == -1)
  return 1;
 return 0;
}

int isFull(stack *s){
 if(s->top == (s->size - 1))
  return 1;
 return 0;
}

stack createIntegerStack(int stackSize){
 stack s;
 s.space = (int*)malloc(stackSize * sizeof(int));
 s.top = -1;
 s.size = stackSize;
 return s;
}

int pushIntegerStack(stack *s, int d){
 if(!isFull(s)){
  s->top = s->top + 1;
  s->space[s->top] = d;
  return 1;
 }
 else
  return 0;
}

int popIntegerStack(stack *s, int *dp){
 if(!isEmpty(s)){
  *dp = s->space[(s->top)--];
  return 1;
 }
 return 0;
}

int freeIntegerStack(stack *s){
 if(s->space == NULL)
  return 0;
 free(s->space);
 s->space = NULL;
 s->top = -1;
 s->size = 0;
 return 1;
}


void main()
{
 stack s1, s2;
    int s1_size, s2_size;
    printf("Enter stack 1 size: ");
    scanf("%d", &s1_size);
    printf("Enter stack 2 size: ");
    scanf("%d", &s2_size);
 s1 = createIntegerStack(s1_size);
 s2 = createIntegerStack(s2_size);
 while(1)
 {
  int d;
  printf("Enter element: ");
  scanf("%d", &d);
  if(pushIntegerStack(&s1, d)){
   continue;
  }
  else{
   if(pushIntegerStack(&s2, d))
    continue;
   else{
    printf("Stack is full.\n");
    break;
   }
  }
 }
    printf("Poping the elements: ");
 while(1)
 {
  int d;
  if(!isEmpty(&s2)){
   if(popIntegerStack(&s2, &d))
    printf("%d ", d);
  }
  else{
   if(!isEmpty(&s1)){
    if(popIntegerStack(&s1, &d))
     printf("%d ", d);
   }
   else
    break;
  }
 }
    printf("\n");
}
