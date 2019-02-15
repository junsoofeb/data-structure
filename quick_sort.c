#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 100 //M�� ������ ����

void swap(int *x, int *y);
int partition(int arr[], int l, int r);
void quicksort(int arr[], int l, int r);


unsigned int data[M]; // ���� ������ ������ �迭
unsigned int data0[M]; // ���Ŀ� ������ ������ �迭

int main() 
{
	int i;
	time_t t;

	srand((unsigned)time(&t));

	for (i = 0; i < M; i++)
		data[i] = rand();


	printf("%d���� ���� ����\n", M);

	printf("���� �� >> \n");
	for (i = 0; i < 100; i++)
	{
		printf("%6d ", data[i]);
		if ((i % 10 == 9))
			printf("\n");
	}
	printf("\n\n");


	// ���� �����Ϳ��� ���Ŀ뵵�� �����ͷ� ����
	for (i = 0; i < 100; i++)
		data0[i] = data[i];

	quicksort(data0, 0, M-1);

	printf("���� �� >> \n");
	for (i = 0; i < 100; i++)
	{
		printf("%6d ", data0[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("\n");
}


{
	int temp = *x;
	*x = *y;
void swap(int *x, int *y)
	*y = temp;
}

int partition(int arr[], int l, int r)
{
	int x = arr[l];
	int i = l + 1;
	int j = r;
	while (1) 
	{
		while (arr[i] <= x && i <= r)
			i++;
		while (arr[j] > x && j >= l) 
			j--;
		if (i < j)
			swap(&arr[i], &arr[j]);
		else break;
	}

	swap(&arr[l], &arr[j]);

	return j;
}

void quicksort(int arr[], int l, int r)
{
	int p;

	if (l < r)
	{
		p = partition(arr, l, r);
		quicksort(arr, l, p - 1);
		quicksort(arr, p + 1, r);
	}
}