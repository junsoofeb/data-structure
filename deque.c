#include<stdio.h>
#define N 10

int deque[N];
int f = -1; // f is (index of front) - 1
int r = -1; // r is index of rear

void deq_push_front(int item);
void deq_push_back(int item);
int deq_pop_front();
int deq_pop_back();
void print_queue();

int main()
{
	deq_pop_front();
	deq_pop_back();
	
	deq_push_front('a');
	print_queue();

	deq_push_back('b');
	print_queue();
	
	deq_push_front('c');
	print_queue();
	
	deq_pop_front();
	print_queue();
	
	deq_pop_back();
	print_queue();

	return 0;
}

void print_queue()
{
	int i;
	for (i = f+1; i < r + 1; i++) // f는 front index - 1이니까 +1 해야 front index부터 출력한다.
	{
		printf("Queue index : %d    item : %c    front_index : %d    rear_index : %d\n", i, deque[i], f+1, r);
	}
	printf("\n");
}

void deq_push_front(int item)
{
	int i;
	if (f == -1) 
	{
		if (r != N - 1)  
		{
			for (i = r; i >= 0; i--) // 한 칸씩 뒤로 밀어주는 역할
				deque[i + 1] = deque[i];
			deque[0] = item;
			r++;
			return;
		}
		else
		{
			printf("Queue is full!\n\n");
			return;
		}
	}

	else 
	{
		deque[f--%N] = item;
		return;
	}
}

void deq_push_back(int item) 
{
	int i;
	if (r == N - 1)
	{
		if (f != -1)
		{
			for (i = 0; i < N - f - 1; i++)// 한 칸씩 앞으로로 밀어주는 역할
				deque[i + 1] = deque[i];
			f = -1;
			r = r - N + i;
			deque[++r] = item;
			return;
		}
		else
		{
			printf("Queue is full!\n\n");
			return;
		}
	}

	else
	{
		deque[++r%N] = item;
		return;
	}
}

int deq_pop_front()
{
	if (r - f <= 0)
	{
		printf("Queue is empty!\n\n");
		return;
	}
	f = f + 1;
	return deque[(f-1) % N];
}
int deq_pop_back() 
{
	if (r - f <= 0)
	{
		printf("Queue is empty!\n\n");
		return;
	}
	r = r - 1;

	return deque[(r+1) % N];
}