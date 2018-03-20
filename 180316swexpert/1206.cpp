/**
*	sw Expert Academy
*	No. 1206 1차원 배열 연습 문제
*	@author	peter9378
*	@date		2018.03.20
*/
#include <iostream>
using namespace std;

int arr[1001];

// max함수 구현
int max(int a, int b)
{
	return a > b ? a : b;
}

// main
int main()
{
	ios::sync_with_stdio(false);

	int T = 10;
	int N;
	while(T--)
	{
		// 조망권의 합은 매번 초기화
		int sum = 0;
		// 건물 개수 입력
		cin >> N;

		// 건물 높이 입력
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		
		// 조망권의 합 계산
		for (int i = 2; i < N - 2; i++)
		{
			int compare = max(max(arr[i - 2], arr[i - 1]), max(arr[i + 1], arr[i + 2]));
			if (compare < arr[i])
				sum += arr[i] - compare;
			else
				continue;
		}

		// 출력
		cout << "#" << 10-T << " " << sum << "\n";
	}

	return 0;
}