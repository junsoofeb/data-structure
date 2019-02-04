#include <stdio.h>

void bubble_sort(int arr[], int len); // �������� ����
void bubble_sort_descent(int arr[], int len); // �������� ����

int main()
{
	int arr[9] = { 6, 2, 4, 1, 9, 3, 8, 5, 7};
	int i;

	printf("BubbleSort ���� �� : ");
	for (i = 0; i < 9; i++)
		printf("%d ", arr[i]);
	printf("\n\n");


	bubble_sort(arr, sizeof(arr) / sizeof(int));

	printf("�������� ���� �� : ");
	for (i = 0; i < 9; i++)
		printf("%d ", arr[i]);
	printf("\n\n");


	bubble_sort_descent(arr, sizeof(arr) / sizeof(int));

	printf("�������� ���� �� : ");
	for (i = 0; i < 9; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

void bubble_sort(int arr[], int len)
{
	int i, j;
	int temp;

	for (i = 0; i < len - 1; i++) // �׻� (�迭�� ���� ���� - 1) �� ���Ѵ�.
	{
		for (j = 0; j < (len - i) - 1; j++) // ��������� ���� ū ���� �� �ڿ� ��ġ�ϰ� �Ǳ⿡, �� ���� ���� ū ���� ���� �ʿ䰡 ����. �׷��� (len - i) - 1 
		{
			if (arr[j] > arr[j + 1]) // ���� ���� ���� ������ ũ�� ��ġ �ٲ۴�
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void bubble_sort_descent(int arr[], int len)
{
	int i, j;
	int temp;

	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < (len - i) - 1; j++) // ��������� ���� ���� ���� �� �ڿ� ��ġ�ϰ� �Ǳ⿡, �� ���� ���� ���� ���� ���� �ʿ䰡 ����. �׷��� (len - i) - 1 
		{
			if (arr[j] < arr[j + 1]) // ���� ���� ���� ������ ������ ��ġ �ٲ۴�
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}