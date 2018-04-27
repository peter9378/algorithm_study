/**
*	baekjoon online judge
*	No. 11652 카드
*	@author	peter9378
*	@date		2018.04.27
*/
#include <iostream>
#include <algorithm>
using namespace std;

// 배열
long long arr[1000001];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 숫자 개수 입력
	int N;
	cin >> N;

	// 숫자 입력
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	// 정렬
	sort(arr, arr + N);

	// 초기값
	int count = 1;
	int max = 1;
	long long result = arr[0];

	// 가장 많이 나온 정수 구하기
	for (int i = 1; i < N; i++)
	{
		// 이전 숫자와 같으면 count++
		if (arr[i] == arr[i - 1])
			count++;
		// 다르면 count를 1로
		else
			count = 1;

		// 최대치보다 count가 많아지면 최대값 갱신, 해당 정수 저장
		if (max < count)
		{
			max = count;
			result = arr[i];
		}
	}

	// 출력
	cout << result;

	return 0;
}