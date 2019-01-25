#include <stdio.h>
#define POOL_SIZE 10

struct record  // record structure
{
	char name[3];
	char number[4];
	struct record * next;
};

// pool of memory
struct record pool[POOL_SIZE];
struct record * top = pool;  // pool is constant.  top is pointer to stack top.

void init_pool();
struct record * new_node();
void free_node(struct record *r);

int main()
{
	printf("Implemetation of new() and free() \n\n");

	return 0;
}

void init_pool() // Initialize the pool
{
	int i;
	struct record *r = pool;
	struct record *s;

	pool[POOL_SIZE - 1].next = NULL;

	for (i = 1; i < POOL_SIZE; i++) {
		s = r++; //r의 주소값에서 POOL_SIZE만큼 주소값 증가 후 s에 대입.
		s->next = r;
	}
}

// Get a node from the pool.  Exit if pool is empty.
struct record * new_node()
{
	struct record * q;
	if (top == NULL)
	{
		printf("Pool is empty. Bye!\n");
		exit(0);
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