/**
*	baekjoon_stepbystep
*	No. 1181 단어 정렬
*	@author	peter9378
*	@date		2018.03.15
*/
#include <iostream>
#include <algorithm>
using namespace std;

// string 대신 간이 string구조체 생성
struct myString {
	// string 길이
	int length;
	// string
	char string[51];
};

// swap함수 구현, 포인터 사용으로 배열에 바로 적용 가능
void swap(myString* a, myString* b)
{
	myString* temp;
	temp = a;
	a = b;
	b = temp;
	return;
}

// myString에 적용 가능한 compare함수 구현
bool compare(myString a, myString b)
{
	if (a.length == b.length)
	{
		for (int i = 0; i < a.length; i++)
		{
			if (a.string[i] == b.string[i])
				continue;
			else if (a.string[i] < b.string[i])
				return true;
			else
				return false;
		}
	}
	return a.length < b.length;
}

// selection sort 구현
void ssort(myString arr[], int size)
{
	int min;
	for (int i = 0; i < size; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			// 구현한 compare함수를 사용해서 비교
			if (compare(arr[j], arr[min]))
				min = j;
		}
		swap(arr[min], arr[i]);
	}
	return;
}

// strcmp 간단하게 구현
bool strcmp(myString a, myString b)
{
	if (a.length != b.length)
		return false;
	else
	{
		for (int i = 0; i < a.length; i++)
		{
			if (a.string[i] != b.string[i])
				return false;
		}
	}
	return true;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	int N;
	cin >> N;

	// N개의 myString 동적할당
	myString* arr = new myString[N];
	int index = 0;

	// 성능 향상을 위해 입력과 동시에 길이 계산
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].string;
		index = 0;
		while (arr[i].string[index])
			index++;
		arr[i].length = index;
	}

	// 정렬
	sort(arr, arr+N, compare);

	// 출력
	cout << arr[0].string << "\n";
	for (int i = 1; i < N; i++)
	{
		// 같은 문자열은 한번만 출력
		if (!strcmp(arr[i], arr[i - 1]))
			printf("%s\n", arr[i].string);
	}

	// 동적할당 해제
	delete[] arr;

	return 0;
}