#include <stdio.h>
#include <stdlib.h>

#define M 20
#define HASH_PRIME 13

typedef struct record
{
	int item;
	struct record * next;
}Record;

Record * hash_table[HASH_PRIME];

int hash(int item);
void add(int item);
void delete(int item);
void search(int item);
void print();

int main()
{
	int i;
	for (i = 0; i < M; i++)
		add(i);
	
	print();
	search(1);
	delete(1);
	search(1);
	print();
}

int hash(int item)
{
	return (item % HASH_PRIME);
}

void add(int item)
{
	int hh = hash(item);
	Record *r = hash_table[hh];
	Record *p;

	p = (Record*)malloc(sizeof(Record));

	if (p == NULL)
	{
		printf("Can't add.  The pool is empty!\n");
		return;
	}

	p->item = item;
	p->next = NULL;

	if (hash_table[hh] == NULL)
		hash_table[hh] = p;
	else
	{
		p->next = r;
		hash_table[hh] = p;
	}
}

void delete(int item)
{
	int hh = hash(item);
	if (hash_table[hh] == NULL)
		return;

	Record* del = NULL;
	if (hash_table[hh]->item == item)
	{
		del = hash_table[hh];
		hash_table[hh] = hash_table[hh]->next;
	}
	else
	{
		Record* node = hash_table[hh];
		Record* next = node->next;
		while (next)
		{
			if (next->item == item)
			{
				node->next = next->next;
				del = next;
				break;
			}
			node = next;
			next = node->next;
		}
	}
	free(del);
}

void search(int item)
{
	Record *r = hash_table[hash(item)];
	Record *p;

	if (hash_table[hash(item)] == NULL) // hash table에 아무것도 없을때 
	{
		printf("Couldn't find the name.\n");
		return;
	}

	if (item == hash_table[hash(item)]->item) // 첫 리스트가 똑같은거
	{
		printf("%d was found.\n", hash_table[hash(item)]->item);
		return;
	}
	else
	{
		p = hash_table[hash(item)];
		while (p != NULL) // 끝까지 진행
		{
			if (item == p->item) //똑같은거 찾기
			{
				printf("%d was found.\n", p->item);
				return;
			}
			p = p->next;
		}
		if (hash_table[hash(item)]->next == NULL || p == NULL)
		{
			printf("Couldn't find item.\n");
			return;
		}
	}
}

void print()
{
	int i;
	for (i = 0; i < HASH_PRIME; i++)
	{
		printf("table index :%d >>> ", i);

		if (hash_table[i] != NULL)
		{
			Record* node = hash_table[i];
		
			while (node->next)
			{		
				printf("%d  ", node->item);
				node = node->next;
			}
			printf("%d\n", node->item);
		}
		else
			printf("This index is empty!\n");
	}
	printf("\n");
}

	