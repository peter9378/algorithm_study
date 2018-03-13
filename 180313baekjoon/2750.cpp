/**
*	baekjoon_stepbystep
*	No. 2750 수 정렬하기
*	@author	peter9378
*	@date		2018.03.14
*/
#include <iostream>
using namespace std;

int arr[1001];

// swap함수 구현, 포인터 사용으로 배열에 바로 적용 가능
void swap(int* a, int* b)
{
	int* temp;
	temp = a;
	a = b;
	b = temp;
	return;
}

// selection sort 구현
void sort(int arr[], int size)
{
	int min;
	for (int i = 0; i < size; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		swap(arr[min], arr[i]);
	}

	return;
}

// insertion sort 구현
void insertion_sort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int temp = arr[i], j;
		for (j = i - 1; j > -1; j--)
		{
			if (arr[j] < temp)
				break;
			arr[j + 1] = arr[j];
		}
		arr[j+1] = temp;
	}
	return;
}

// bubble sort 구현
void bubble_sort(int arr[], int size)
{
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
	return;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	// 입력받을 숫자 개수
	int T;
	cin >> T;

	// 정렬할 숫자들 입력
	for (int i = 0; i < T; i++)
		cin >> arr[i];

	// 정렬
	sort(arr, T);

	// 출력
	for (int i = 0; i < T; i++)
		cout << arr[i] << "\n";

	return 0;
}