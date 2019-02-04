#include <stdio.h>

void bubble_sort(int arr[], int len); // 오름차순 정렬
void bubble_sort_descent(int arr[], int len); // 내림차순 정렬

int main()
{
	int arr[9] = { 6, 2, 4, 1, 9, 3, 8, 5, 7};
	int i;

	printf("BubbleSort 정렬 전 : ");
	for (i = 0; i < 9; i++)
		printf("%d ", arr[i]);
	printf("\n\n");


	bubble_sort(arr, sizeof(arr) / sizeof(int));

	printf("오름차순 정렬 후 : ");
	for (i = 0; i < 9; i++)
		printf("%d ", arr[i]);
	printf("\n\n");


	bubble_sort_descent(arr, sizeof(arr) / sizeof(int));

	printf("내림차순 정렬 후 : ");
	for (i = 0; i < 9; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

void bubble_sort(int arr[], int len)
{
	int i, j;
	int temp;

	for (i = 0; i < len - 1; i++) // 항상 (배열의 원소 개수 - 1) 번 비교한다.
	{
		for (j = 0; j < (len - i) - 1; j++) // 결과적으로 가장 큰 수가 맨 뒤에 위치하게 되기에, 맨 뒤의 가장 큰 수는 비교할 필요가 없다. 그래서 (len - i) - 1 
		{
			if (arr[j] > arr[j + 1]) // 앞의 값이 뒤의 값보다 크면 위치 바꾼다
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
		for (j = 0; j < (len - i) - 1; j++) // 결과적으로 가장 작은 수가 맨 뒤에 위치하게 되기에, 맨 뒤의 가장 작은 수는 비교할 필요가 없다. 그래서 (len - i) - 1 
		{
			if (arr[j] < arr[j + 1]) // 앞의 값이 뒤의 값보다 작으면 위치 바꾼다
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}