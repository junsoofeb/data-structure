#include <stdio.h>

int stact_array[100];//array of size 100
int t = 0; // t  == (index of stack_top) + 1

int pop();
void push(int x);
void print_stack();

int main()
{
	pop();
	push('a');
	push('b');
	push('c');
	print_stack();

	return;
}


int pop()
{
	if (t < 1)
	{
		printf("Stack is empty!\n\n");
		return -1;
	}

	t = t - 1;
	return stact_array[t];
}

void push(int x)
{
	if (t >= 100)
	{
		printf("Stack is full!\n\n");
		return;
	}

	stact_array[t] = x;
	t = t + 1; 
}

void print_stack()
{
	int i;
	for (i = 0; i < t; i++)
	{
		printf("stack index : %d     item : %c\n", i, stact_array[i]);
	}
}