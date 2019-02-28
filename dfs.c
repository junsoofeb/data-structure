#include <stdio.h>

#define N 10 // N은 vertex의 개수

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
int state[N]; // 상태 저장용 배열
int stack[N]; // DFS에 사용할 스택
int t; // (stack top + 1)을 가리키는 인덱스

void init_state() // 모두 방문하지 않은 상태로 초기화
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
	int current = 0; // 현재 상태를 저장할 변수
	int v = 0;
	struct node* i; // 초기상태 유지하기위해 i로 이동
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