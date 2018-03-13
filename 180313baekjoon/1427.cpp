/**
*	baekjoon_stepbystep
*	No. 1427 소트인사이드
*	@author	peter9378
*	@date		2018.03.14
*/
#include <iostream>
using namespace std;

char N[11];

// swap함수 구현, 포인터 사용으로 배열에 바로 적용 가능
void swap(char* a, char* b)
{
	char* temp;
	temp = a;
	a = b;
	b = temp;
	return;
}

// selection sort로 구현
void sort(char arr[], int size)
{
	int min;
	for (int i = 0; i < size; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[min] < arr[j])
				min = j;
		}
		swap(arr[min], arr[i]);
	}

	return;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	// 정렬하고자하는 수 N 입력
	cin >> N;

	// 숫자의 자리수를 구함
	int size;
	for (int i = 0; i < 11; i++)
	{
		if (N[i] == '\0')
		{
			size = i;
			break;
		}
	}

	// 앞자리 수에 0이 있을 경우 제거
	int count = 0;
	while (N[0] == '0')
	{
		for (int i = 0; i < size; i++)
		{
			N[i] = N[i + 1];
		}
		count++;
	}
	// 제거한 0의 개수만큼 size감소
	size -= count;

	// 정렬
	sort(N, size);

	// 출력
	cout << N;

	return 0;
}