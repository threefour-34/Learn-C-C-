#include<stdlib.h>
#include<stdio.h>

int main()
{
	int n;
	printf("please enter a number:");
	scanf_s("%d",& n);
	int* arr;
	arr = (int*)malloc(n * sizeof(int));//动态内存分布 C99之前不能int arr[n]
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	for (int i = n-1; i > -1; i--)
	{
		printf(" %d ", arr[i]);
	}
	free(arr);//attention please
	system("pause");
	return 0;

}