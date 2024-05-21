#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct mystack
{
    int *p, top, size;
};


typedef struct mystack stack;

 
stack* createIntegerStack(int stackSize)
{
	stack *s1 = NULL;
	s1 = (stack*) malloc(sizeof(stack));
	if(s1 == NULL)
	{
		return NULL;
	}
	s1->top = 0;
	s1->size = stackSize;
	s1->p = (int*) malloc(s1->size*sizeof(int));
	if(s1->p == NULL)
	{
		free(s1);
		return NULL;
    }
    return s1;
}


int pushIntegerStack(stack *s, int d)
{
	if(s == NULL || s->top == s->size)
	{
		return 0;
    }
    s->p[s->top] = d;
    s->top = s->top + 1;
    return 1;
}


int popIntegerStack(stack *s, int *dp)
{
	if(s == NULL || s->top == 0)
	{
		return 0;
    }
    s->top = s->top - 1;
    *dp = s->p[s->top];
    return 1;
}

int freeIntegerStack(stack *s)
{
	if(s == NULL)
	{
		return 0;
    }
    if(s->p != NULL)
	{
		free(s->p);
	}
	free(s);
	return 1;
}

int isIntegerStackEmpty(stack *s)
{
	if(s == NULL || s->top == 0)
	{
		return 1;
    }
    return 0;
}

int operate(char x, int op1, int op2)
{
	switch(x)
	{
		case '+': return (op1 + op2);
		case '-': return (op1 - op2);
		case '*': return (op1 * op2);
		case '/': return (op1 / op2);
		case '$': 
			{
				int i, p = 1;
				for(i = 0; i < op2; i++)
				{
					p = p * op1;
				}
				return p;
			}
	}
}

int precedence(char x)
{
	switch(x)
	{
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		case '$': return 3;
	}
}

int main()
{
	while(1)
	{
		int p;
		printf("Menu\n");
		printf("1. Evaluate a postfix expression\n");
		printf("2. Convert an infix expression to postfix expression\n");
		printf("3. Exit\n");
		printf("Enter your option: ");
		scanf("%d", &p);
		switch(p)
		{
			case 1: 
				{
					char exp[100];
					int i, op1, op2, value, intvalue = 0, answer;
					printf("Enter the postfix expression: ");
					scanf(" %[^\n]s", exp);
					stack *s = createIntegerStack(100);
					for(i = 0; i < strlen(exp); i++)
					{
						if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '$')
						{
							popIntegerStack(s, &op2);
							popIntegerStack(s, &op1);
							value = operate(exp[i], op1, op2);
							pushIntegerStack(s, value);
						}
						else if(exp[i] == ' ')
						{
							pushIntegerStack(s, intvalue);
							intvalue = 0;
						}
						else
						{
							intvalue = (intvalue * 10) + (int) (exp[i] - '0');
						}
					}
					popIntegerStack(s, &answer);
					printf("The value of the postfix expression: %d\n", answer);
					freeIntegerStack(s);
				}
				break;
			case 2: 
				{
					char exp[100], ans[100];
					int i, j = 0, temp;
					printf("Enter the infix expression: ");
					scanf("%s", exp);
					stack *s = createIntegerStack(100);
					for(i = 0; i < strlen(exp); i++)
					{
						if((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= '0' && exp[i] <= '9'))
						{
							ans[j] = exp[i];
							j++;
						}
						else if(exp[i] == '(')
						{
							pushIntegerStack(s, '(');
						}
						else if(exp[i] == ')')
						{
							while(isIntegerStackEmpty(s) == 0)
							{
								popIntegerStack(s, &temp);
								if(temp == '(')
								{
									break;
								}
								else
								{
									ans[j] = (char) temp;
									j++;
								}
							}
							if(temp != '(')
							{
								printf("Invalid expression\n");
								return 0;
							}
						}
						else
						{
							while(isIntegerStackEmpty(s) == 0)
							{
								popIntegerStack(s, &temp);
								if(precedence((char) temp) > precedence(exp[i]))
								{
									ans[j] = (char) temp;
									j++;
								}
								else
								{
									pushIntegerStack(s, temp);
									break;
								}
							}
							pushIntegerStack(s, (int) exp[i]);
						}
					}
					while(isIntegerStackEmpty(s) == 0)
					{
						popIntegerStack(s, &temp);
						ans[j] = (char) temp;
						j++;
					}
					ans[j] = '\0';
					printf("The postfix expression is: %s\n", ans);
				}
				break;					
			case 3: return 0;
			default :
			{
				printf("Invalid option entered\n");
			}
			break;
		}
    }
    return 0;
}