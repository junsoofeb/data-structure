#include <stdio.h>

int queue_array[100];
int f = -1; // f is (index of front) - 1
int r = -1; // r is index of rear

int pop();
void push(int x);
void print_queue();

int main()
{
	pop();
	push('a');
	print_queue();
	push('b');
	print_queue();
	push('c');
	print_queue();
	
	return 0;
}

int pop()
{
	if (r - f <= 0)
	{
		printf("Queue is empty!\n\n");
		return;
	}

	f = f + 1;
	return queue_array[f % 100];
}

void push(int x)
{
	if (r - f >= 100)
	{
		printf("Queue is full!\n\n");
		return;
	}

	r = r + 1;
	queue_array[r % 100] = x;
}

void print_queue()
{
	int i;
	for (i = 0; i < r + 1; i++)
	{
		printf("Queue index : %d    item : %c    front_index : %d    rear_index : %d\n", i, queue_array[i], f, r);
	}
	printf("\n");
}