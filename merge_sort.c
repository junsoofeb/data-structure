#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 100 //M�� ������ ����

void mergesort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

unsigned int data[M]; // ���� ������ ������ �迭
unsigned int data0[M], data1[M]; // ���Ŀ� ������ ������ �迭

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
		data1[i] = data0[i] = data[i];

	mergesort(data0, 0, M - 1);

	printf("���� �� >> \n");
	for (i = 0; i < M; i++)
	{
		printf("%6d ", data0[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("\\n");
}

// mergesort()�� ���Ұ� 1�� ���� ������ ������ �����Ѵ�. �����ϴ� ���� �ƴ�.
void mergesort(int arr[], int left, int right) 
{
	int mid;

	if (left < right) // �迭 �ӿ� ���Ұ� 2�� �̻��̸� �����Ѵ�.
	{
		mid = (left + right) / 2; // ex) (0 + 99) / 2 = 49.5���� int�� �Ҽ����� ������ ������ 49�� mid
		mergesort(arr, left, mid); 
		mergesort(arr, mid + 1, right); 
		merge(arr, left, mid, right); // ���� ������ ����Ǵ� �κ��� merge()�̴�
	}
}

// arr[left ~ mid]�� arr[mid+1 ~ right]�� ����
void merge(int arr[], int left, int mid, int right) 
{
	// i: ���� �迭�� ���� �ε���
	// j: ������ �迭�� ���� �ε���
	// k: ���� �� �迭�� ������ �迭�� �ε���
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	// ���� �迭�� ������ �迭 ���ϸ鼭 �� �迭�� �����ؼ� ����
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
