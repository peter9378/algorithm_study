/**
*	baekjoon_stepbystep
*	No. 2751 수 정렬하기 2
*	@author	peter9378
*	@date		2018.03.14
*/
#include <iostream>
using namespace std;

int arr[1000001];

// swap함수 구현, 포인터 사용으로 배열에 바로 적용 가능
void swap(int* a, int* b)
{
	int* temp;
	temp = a;
	a = b;
	b = temp;
	return;
}

void print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";
	return;
}

// binary heap sort를 사용하기 위해 heapify함수 구현
void heapify(int arr[], int size, int root)
{
	cout << "now root : " << root << "\n";
	print(arr, size);
	// heap을 만들기 위한 left child, right child, root 초기 인덱스
	int left_child = (root + 1) * 2 - 1;
	int right_child = left_child + 1;
	int max = root;

	// left child가 더 작은 경우
	if (left_child < size && arr[left_child] > arr[max])
		max = left_child;

	// right child가 더 작은 경우
	if (right_child < size && arr[right_child] > arr[max])
		max = right_child;

	// 자식이 부모보다 더 작아서 swap해야하는 경우 swap하고 다시 heapify
	if (max != root)
	{
		swap(arr[root], arr[max]);
		heapify(arr, size, max);
	}
	return;
}

// binary heap sort 구현
void heap_sort(int arr[], int size)
{
	int count = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		// 가장 큰 숫자를 맨 뒤로 이동
		swap(arr[0], arr[i]);
		// 
		heapify(arr, i, 0);
		count++;
	}
	cout << count << endl;
	return;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	// 입력받을 숫자 개수
	int T;
	cin >> T;

	// 정렬할 숫자들 입력, 0-base array사용
	for (int i = 0; i < T; i++)
		cin >> arr[i];

	// heapify
	for (int i = T / 2 - 1; i >= 0; i--)
		heapify(arr, T, i);

	// 정렬
	heap_sort(arr, T);

	// 출력
	for (int i = 0; i < T; i++)
		cout << arr[i] << "\n";

	return 0;
}