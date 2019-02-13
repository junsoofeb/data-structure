#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 100 //M�� ������ ����

void bucket(int);

unsigned int data[M]; // ���� ������ ������ �迭
unsigned int data0[M], data1[M]; // ���Ŀ� ������ ������ �迭

int main()
{
	int i;
	time_t t;

	srand((unsigned)time(&t)); 

	for (i = 0; i < M; i++) 
		data[i] = rand();
	

	printf("%d���� ���� ����\n",M);

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
	
	bucket(M); 

	printf("���� �� >> \n");
	for (i = 0; i < 100; i++)
	{
		printf("%6d ", data0[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("\\n");
}


// bucket�� ũ�� : 256 
// 1����Ʈ�� 256(2^8)���� ��Ÿ�� �� �ֱ⶧���� ����Ʈ ������ ��Ŷ�� ��� ���ؼ��̴�. 256�������� �� �� �ִ�.
void bucket(int N)
{
	unsigned int *data_r, *data_w; // ���Ŀ� ������ �迭�� ����� read , write�뵵 ������
	int count[256]; 
	int k[256];   // k�� �ε���
	int i, x;
	int phase, div = 1;

	for (phase = 1; phase <= 4; phase++) { // sizeof(int)�� 4����Ʈ�ϱ� phase 4��
		if (phase % 2 == 1) {              // phase���� �б�, ���� �迭 ��ü
			data_r = data0;
			data_w = data1;
		}
		else {
			data_r = data1;
			data_w = data0;
		}


		for (i = 0; i < 256; i++) // �ʱ�ȭ
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

		div = div * 256; // ���� ����Ʈ�� �Ѿ
	}
}

