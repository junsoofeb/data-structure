#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 100 //M�� ������ ����

void insertion_sort(int arr[], int len);

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

	insertion_sort(data0, sizeof(data0) / sizeof(int));

	printf("���� �� >> \n");
	for (i = 0; i < M; i++)
	{
		printf("%6d ", data0[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("\n");
}


// ���� ��ġ����, �Ʒ� ���ҵ�� ���Ͽ� �ڽ��� �� ��ġ�� ã�� �����ϴ� ������� �����Ѵ�.
void insertion_sort(int arr[], int len)
{
	int i, j; // i�� ���� �ε��� , j�� ���� �ε���
	int temp = 0;

	for (i = 1; i < len; i++) // ���� �ε����� 0�� �ƴϰ� 1�̴�. 2��° �ε������� �����Կ� ����!
	{
		int key = arr[i]; // key�� ������ ���� ����

		j = i - 1; // ���� �ε����� (���� �ε��� - 1)�� ����


		
		//key���� ���� �ε����� ������ Ŭ ������ j�� �ٿ����� �ݺ��Ѵ�.
		while ( (j>=0) && (key < arr[j]) )
		{
			temp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = temp; 
			j--;
		}

		// ���Ժ����� �� ū ��쿡�� ���� �ε��� ���� �����Ѵ�.
		arr[j + 1] = key;
	}
}