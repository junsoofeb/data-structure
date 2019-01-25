#include <stdio.h>
#define POOL_SIZE 10

struct record  // record structure
{
	int item;
	struct record * next;
};

// pool of memory
struct record pool[POOL_SIZE];
struct record * top = pool;  // pool is constant.  top is pointer to stack top.
struct record * data = NULL; // stack을 가리키는 용도

void init_pool();
struct record * new_node();
void free_node(struct record *r);
int pop();
void push(int x);
void print_stack();

int main()
{
	init_pool();

	pop();

	push('a');
	print_stack();

	push('b');
	print_stack();

	push('c');
	print_stack();

	return 0;
}

void init_pool() // Initialize the pool
{
	int i;
	struct record *q = pool;

	for (i = 0; i < POOL_SIZE - 1; i++) //첫 번째부터 마지막 전까지
	{
		q->next = q + POOL_SIZE;
		q = q + POOL_SIZE;
	}

	pool[POOL_SIZE - 1].next = NULL; // last block
	top = pool;
}

// Get a node from the pool.  Exit if pool is empty.
struct record * new_node()
{
	struct record * q;
	if (top == NULL)
	{
		printf("Pool is empty. Bye!\n");
		return;
	}
	q = top;
	top = q->next;

	return q;
}

// Push a node to the pool.
void free_node(struct record *r)
{
	r->next = top;
	top = r;
}

int pop()
{
	int ret;
	struct record* p;
	if (data == NULL)
	{
		printf("Stack is empty!\n\n");
		return;
	}

	ret = data->item;
	p = data;
	data = data->next;
	free_node(p);

	return ret;
}

void push(int x)
{
	struct record* p;
	p = new_node();
	if (p == NULL)
	{
		printf("Stack is full!\n\n");
		return;
	}

	p->item = x;
	p->next = data;
	data = p;
}

void print_stack()
{
	struct record* p;
	p = data;
	while (p != NULL)
	{
		printf("%c\n", p->item);
		p = p->next;
	}
	printf("\n");
}