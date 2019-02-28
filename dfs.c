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
int stack[N]; // DFS�� ����� ����
int t; // (stack top + 1)�� ����Ű�� �ε���

void init_state() // ��� �湮���� ���� ���·� �ʱ�ȭ
{
	int i;
	for (i = 0; i < N; i++)
		state[i] = UNDISCOVERED;
}

void init_stack()
{
	int i;
	for (i = 0; i < N; i++)
		stack[i] = 0;
	t = 0;
}

int pop()
{
	if (t < 1)
	{
		printf("Stack is empty!\n\n");
		return -1;
	}

	t = t - 1;
	return stack[t];
}

void push(int x)
{
	if (t >= N)
	{
		printf("Stack is full!\n\n");
		return;
	}

	stack[t] = x;
	t = t + 1;
}

int DFS(int start, int goal)
{
	init_parent();
	init_stack();
	init_state();
	int current = 0; // ���� ���¸� ������ ����
	int v = 0;
	struct node* i; // �ʱ���� �����ϱ����� i�� �̵�
	state[start] = DISCOVERED;
	push(start);
	while (t < 1) // while(stack is not empty)
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
			}
			i = i->next;
		}
		state[current] = PROCESSED;
	}
	return -1;
}