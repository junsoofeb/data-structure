#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 100 //M은 숫자의 개수

void heap_sort(int arr[], int len);
int parent(int child);

unsigned int data[M]; // 원본 데이터 저장할 배열
unsigned int data0[M];// 정렬용 데이터 저장할 배열

int main()
{
	int i;
	time_t t;

	srand((unsigned)time(&t));


	// 원본 데이터에 난수 저장
	for (i = 0; i < M; i++)
		data[i] = rand();


	printf("%d개의 난수 생성\n", M);

	printf("정렬 전 >> \n");
	for (i = 0; i < M; i++)
	{
		printf("%6d ", data[i]);
		if ((i % 10 == 9))
			printf("\n");
	}
	printf("\n\n");

	// 원본 데이터에서 정렬용도의 데이터로 복사
	for (i = 0; i < M; i++)
		data0[i] = data[i];
	

	heap_sort(data0, sizeof(data0) / sizeof(int)); // 힙 생성

	for (int i = M - 1; i >= 0; i--) 
	{
		// 가장큰 숫자(root)를 맨 마지막 원소와 교체
		int temp = data0[i];
		data0[i] = data0[0];
		data0[0] = temp;

		// 맨 마지막 원소를 제외하고 다시 힙 생성하며 정렬
		heap_sort(data0, i);
	}

	printf("정렬 후 >> \n");
	for (i = 0; i < M; i++)
	{
		printf("%6d ", data0[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("\n");
}

int parent(int child)
{
	return (child - 1) / 2;
}

void heap_sort(int arr[], int num) 
{
	for (int i = 1; i < num; i++) 
	{
		int child = i;
		while (child > 0) 
		{
			int root = parent(child);
			if (arr[root] < arr[child]) 
			{
				int temp = arr[root];
				arr[root] = arr[child];
				arr[child] = temp;
			}
			child = root;
		}
	}
}