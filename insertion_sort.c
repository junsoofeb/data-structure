#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 100 //M은 숫자의 개수

void insertion_sort(int arr[], int len);

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

	insertion_sort(data0, sizeof(data0) / sizeof(int));

	printf("정렬 후 >> \n");
	for (i = 0; i < M; i++)
	{
		printf("%6d ", data0[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("\n");
}


// 현재 위치에서, 아래 원소들과 비교하여 자신이 들어갈 위치를 찾아 삽입하는 방법으로 정렬한다.
void insertion_sort(int arr[], int len)
{
	int i, j; // i는 현재 인덱스 , j는 비교할 인덱스
	int temp = 0;

	for (i = 1; i < len; i++) // 시작 인덱스가 0이 아니고 1이다. 2번째 인덱스부터 시작함에 주의!
	{
		int key = arr[i]; // key는 삽입을 위한 변수

		j = i - 1; // 비교할 인덱스를 (현재 인덱스 - 1)로 설정


		
		//key값이 비교할 인덱스의 값보다 클 때까지 j를 줄여가며 반복한다.
		while ( (j>=0) && (key < arr[j]) )
		{
			temp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = temp; 
			j--;
		}

		// 삽입변수가 더 큰 경우에는 비교한 인덱스 위에 저장한다.
		arr[j + 1] = key;
	}
}