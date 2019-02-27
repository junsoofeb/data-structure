#include <stdio.h>

#define N 10 // N�� vertex�� ����

struct node 
{
	int index;
	struct node * next;
};

enum state_of_vertices
{
	UNDISCOVERED = -1, DISCOVERED, PROCESSED
};

struct node * adj_list[N];
int state[N]; // ���� ����� �迭
int parent[N]; // �θ� ����� �迭
int queue[N]; // BFS�� ����� ť
int f, r; // f = (queue index of front) -1 , r = queue index of rear


void init_state() // ��� �湮���� ���� ���·� �ʱ�ȭ
{
	int i;
	for (i = 0; i < N; i++)
		state[i] = UNDISCOVERED;
}


void init_parent() // �θ� ���� ����(-1)�� �ʱ�ȭ
{
	int i;
	for (i = 0; i < N; i++)
		parent[i] = -1;
}


void init_queue()
{
	int i;
	for (i = 0; i < N; i++)
		queue[i] = 0;
	f = -1;
	r = -1;
}

int pop()
{
	if (r <= f)
	{
		printf("UNDERFLOW!\n");
		return;
	}
	f = f + 1;
	return queue[f%N];
}

void push(int x)
{
	if (r - f >= N)
	{
		printf("OVERFLOW!\n");
		return;
	}
	r = r + 1;
	queue[r%N] = x;
}

int BFS(int start, int goal)
{
	init_parent();
	init_queue();
	init_state();
	int current = 0; // ���� ���¸� ������ ����
	int v = 0;
	struct node* i; // �ʱ���� �����ϱ����� i�� �̵�
	state[start] = DISCOVERED;
	push(start);
	while ((r - f) > 0) // while(queue is not empty)
	{
		current = pop();
		i = adj_list[current];
		while (i != NULL)
		{
			v = i->index;

			if (state[v] == UNDISCOVERED)
			{
				push(v);
				state[v] = DISCOVERED;
				parent[v] = current;
				if (v == goal)
					return v;
			}
			i = i->next;
		}
		state[current] = PROCESSED;
	}
	return -1;
}