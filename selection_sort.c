#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 100 //M은 숫자의 개수

void selection_sort(int arr[], int len);

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

	selection_sort(data0, sizeof(data0)/sizeof(int));

	printf("정렬 후 >> \n");
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
	int temp = 0; // 값 임시 저장용

	for (i = 0; i < len - 1; i++)
	{
		int tmp = i; // 인덱스 이동용, 맨 앞 인덱스로 초기화

		for (j = i + 1; j < len; j++)
		{
			if (arr[tmp] >= arr[j]) // 가장 작은 값의 인덱스를 tmp에 저장
				tmp = j;
		}

		// 현재 인덱스를 가장 작은 값으로 바꾼다.
		temp = arr[i];
		arr[i] = arr[tmp];
		arr[tmp] = temp;
		// 이후 for문 반복
	}
}