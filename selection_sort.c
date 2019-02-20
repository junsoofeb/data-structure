#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 100 //M�� ������ ����

void selection_sort(int arr[], int len);

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

	selection_sort(data0, sizeof(data0)/sizeof(int));

	printf("���� �� >> \n");
	for (i = 0; i < M; i++)
	{
		printf("%6d ", data0[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("\\n");
}

void selection_sort(int arr[], int len)
{
	int i, j;
	int temp = 0; // �� �ӽ� �����

	for (i = 0; i < len - 1; i++)
	{
		int tmp = i; // �ε��� �̵���, �� �� �ε����� �ʱ�ȭ

		for (j = i + 1; j < len; j++)
		{
			if (arr[tmp] >= arr[j]) // ���� ���� ���� �ε����� tmp�� ����
				tmp = j;
		}

		// ���� �ε����� ���� ���� ������ �ٲ۴�.
		temp = arr[i];
		arr[i] = arr[tmp];
		arr[tmp] = temp;
		// ���� for�� �ݺ�
	}
}