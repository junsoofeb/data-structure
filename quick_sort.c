#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 100 //M은 숫자의 개수

void swap(int *x, int *y);
int partition(int arr[], int l, int r);
void quicksort(int arr[], int l, int r);


unsigned int data[M]; // 원본 데이터 저장할 배열
unsigned int data0[M]; // 정렬용 데이터 저장할 배열

int main() 
{
	int i;
	time_t t;

	srand((unsigned)time(&t));

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

	quicksort(data0, 0, M-1);

	printf("정렬 후 >> \n");
	for (i = 0; i < M; i++)
	{
		printf("%6d ", data0[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("\n");
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
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
