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
int parent[N]; // 부모 저장용 배열
int queue[N]; // BFS에 사용할 큐
int f, r; // f = (queue index of front) -1 , r = queue index of rear

void init_adj_list() // 모두 NULL포인터로 초기화
{
  int i,j;
  struct node *p;

  for (i=0; i<N; i++)
    adj_list[i]=NULL;
}

void init_state() // 모두 방문하지 않은 상태로 초기화
{
	int i;
	for (i = 0; i < N; i++)
		state[i] = UNDISCOVERED;
}


void init_parent() // 부모가 없는 상태(-1)로 초기화
{
	int i;
	for (i = 0; i < N; i++)
		parent[i] = -1;
}


void init_queue() // 큐의 원소와 인덱스 초기화
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
	int current = 0; // 현재 상태를 저장할 변수
	int v = 0;
	struct node* i; // 초기상태 유지하기위해 i로 이동
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
