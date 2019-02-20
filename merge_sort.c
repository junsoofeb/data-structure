#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 100 //M은 숫자의 개수

void mergesort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

unsigned int data[M]; // 원본 데이터 저장할 배열
unsigned int data0[M], data1[M]; // 정렬용 데이터 저장할 배열

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
		data1[i] = data0[i] = data[i];

	mergesort(data0, 0, M - 1);

	printf("정렬 후 >> \n");
	for (i = 0; i < M; i++)
	{
		printf("%6d ", data0[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("\\n");
}

// mergesort()는 원소가 1개 남을 때까지 반으로 분할한다. 정렬하는 것은 아님.
void mergesort(int arr[], int left, int right) 
{
	int mid;

	if (left < right) // 배열 속에 원소가 2개 이상이면 실행한다.
	{
		mid = (left + right) / 2; // ex) (0 + 99) / 2 = 49.5지만 int는 소수점을 버리기 때문에 49가 mid
		mergesort(arr, left, mid); 
		mergesort(arr, mid + 1, right); 
		merge(arr, left, mid, right); // 실제 정렬이 수행되는 부분은 merge()이다
	}
}

// arr[left ~ mid]와 arr[mid+1 ~ right]의 정렬
void merge(int arr[], int left, int mid, int right) 
{
	// i: 왼쪽 배열에 대한 인덱스
	// j: 오른쪽 배열에 대한 인덱스
	// k: 위의 두 배열을 병합한 배열의 인덱스
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	// 왼쪽 배열과 오른쪽 배열 비교하면서 새 배열에 정렬해서 저장
	while (i <= mid && j <= right) 
	{
		if (arr[i] <= arr[j])
			data1[k++] = arr[i++];
		else
			data1[k++] = arr[j++];
	}

	if (i > mid) 
	{
		for (l = j; l <= right; l++)
			data1[k++] = arr[l];
	}
	else 
	{
		for (l = i; l <= mid; l++)
			data1[k++] = arr[l];
	}

	for (l = left; l <= right; l++) 
	{
		arr[l] = data1[l];
	}
}
