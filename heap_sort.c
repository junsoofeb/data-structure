#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 100 //M�� ������ ����

void heap_sort(int arr[], int len);
int parent(int child);

unsigned int data[M]; // ���� ������ ������ �迭
unsigned int data0[M];// ���Ŀ� ������ ������ �迭

int main()
{
	int i;
	time_t t;

	srand((unsigned)time(&t));


	// ���� �����Ϳ� ���� ����
	for (i = 0; i < M; i++)
		data[i] = rand();


	printf("%d���� ���� ����\n", M);

	printf("���� �� >> \n");
	for (i = 0; i < M; i++)
	{
		printf("%6d ", data[i]);
		if ((i % 10 == 9))
			printf("\n");
	}
	printf("\n\n");

	// ���� �����Ϳ��� ���Ŀ뵵�� �����ͷ� ����
	for (i = 0; i < M; i++)
		data0[i] = data[i];
	

	heap_sort(data0, sizeof(data0) / sizeof(int)); // �� ����

	for (int i = M - 1; i >= 0; i--) 
	{
		// ����ū ����(root)�� �� ������ ���ҿ� ��ü
		int temp = data0[i];
		data0[i] = data0[0];
		data0[0] = temp;

		// �� ������ ���Ҹ� �����ϰ� �ٽ� �� �����ϸ� ����
		heap_sort(data0, i);
	}

	printf("���� �� >> \n");
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