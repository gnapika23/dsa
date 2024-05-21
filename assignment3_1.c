#include <stdio.h>
#include <stdlib.h>

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

void displayIntegerTop(stack *s){
 if(!isEmpty(s)){
  printf("Top: %d\n", s->space[s->top]);
 }
 else
  printf("Stack is empty.\n");
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


int main()
{
 stack s;
 int size;
 printf("Enter stack size: ");
 scanf("%d", &size);
 s = createIntegerStack(size);
 int input = 1;
 while(input){
  printf("1. Push element.\n2. Pop element.\n3. Display top.\n4. Free stack.\n5. Create another Stack. \nEnter input(0 to exit): ");
  scanf("%d", &input);
  if(input == 1){
   printf("Enter element to push: ");
   int elem;
   scanf("%d", &elem);
   if(pushIntegerStack(&s, elem))
    printf("%d was pushed.\n", elem);
   else
    printf("Pushing failed.\n");
  }
  else if(input == 2){
   int elem;
   if(popIntegerStack(&s, &elem))
    printf("Pop was successfull. Element: %d \n", elem);
   else
    printf("Pop failed.\n");
  }
  else if(input == 3){
   displayIntegerTop(&s);
  }
  else if(input == 4){
   if(freeIntegerStack(&s)){
    printf("Stack was freed succesfully.\n");
   }
   else
    printf("Stack freeing failed.\n");
  }
  else if(input == 5){
   printf("Enter stack size: ");
   scanf("%d", &size);
   s = createIntegerStack(size);
  }
  else
   printf("Enter a valid input.\n");
 }
}