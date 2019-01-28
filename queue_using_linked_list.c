#include <stdio.h>
#define POOL_SIZE 10

struct record  // record structure
{
	int item;
	struct record * next;
};

// pool of memory
struct record pool[POOL_SIZE];
struct record * top = pool;  // pool is constant.  top is pointer to stack(pool) top.
struct record * f = NULL; // pointer to front of the queue
struct record * r;// pointer to rear of the queue , r is dangling pointer


void init_pool();
struct record * new_node();
void free_node(struct record *r);
int pop();
void push(int x);
void print_queue();

int main()
{
	init_pool();

	pop();

	push('a');
	print_queue();

	push('b');
	print_queue();

	push('c');
	print_queue();

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
	if (f == NULL)
	{
		printf("Stack is empty!\n\n");
		return;
	}

	ret = f->item;
	p = f;
	f = f->next;
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
	p->next = NULL;

	if (f == NULL) f = p;

	else r->next = p;

	r = p;
}

void print_queue()
{
	struct record* p;
	p = f;
	while (p != NULL)
	{
		printf("%c\n", p->item);
		p = p->next;
	}
	printf("\n");
}