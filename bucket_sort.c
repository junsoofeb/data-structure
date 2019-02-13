#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 100 //M은 숫자의 개수

void bucket(int);

unsigned int data[M]; // 원본 데이터 저장할 배열
unsigned int data0[M], data1[M]; // 정렬용 데이터 저장할 배열

int main()
{
	int i;
	time_t t;

	srand((unsigned)time(&t)); 

	for (i = 0; i < M; i++) 
		data[i] = rand();
	

	printf("%d개의 난수 생성\n",M);

	printf("정렬 전 >> \n");
	for (i = 0; i < 100; i++)
	{
		printf("%6d ", data[i]);
		if ((i % 10 == 9))
			printf("\n");
	}	
	printf("\n\n");


	// 원본 데이터에서 정렬용도의 데이터로 복사
	for (i = 0; i < 100; i++) 
			data0[i] = data[i];
	
	bucket(M); 

	printf("정렬 후 >> \n");
	for (i = 0; i < 100; i++)
	{
		printf("%6d ", data0[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("\\n");
}


// bucket의 크기 : 256 
// 1바이트로 256(2^8)까지 나타낼 수 있기때문에 바이트 단위로 버킷에 담기 위해서이다. 256진법으로 볼 수 있다.
void bucket(int N)
{
	unsigned int *data_r, *data_w; // 정렬용 데이터 배열에 사용할 read , write용도 포인터
	int count[256]; 
	int k[256];   // k는 인덱스
	int i, x;
	int phase, div = 1;

	for (phase = 1; phase <= 4; phase++) { // sizeof(int)가 4바이트니까 phase 4개
		if (phase % 2 == 1) {              // phase마다 읽기, 쓰기 배열 교체
			data_r = data0;
			data_w = data1;
		}
		else {
			data_r = data1;
			data_w = data0;
		}


		for (i = 0; i < 256; i++) // 초기화
			count[i] = 0;

		for (i = 0; i < N; i++) {
			x = (data_r[i] / div) % 256;
			count[x]++; 
		}

	

		k[0] = 0;

		for (i = 1; i < 256; i++)
			k[i] = k[i - 1] + count[i - 1];


		for (i = 0; i < N; i++) {
			x = (data_r[i] / div) % 256;
			data_w[k[x]] = data_r[i]; 
			k[x]++;              
		}

		div = div * 256; // 다음 바이트로 넘어감
	}
}

