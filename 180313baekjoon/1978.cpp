/**
*	baekjoon_stepbystep
*	No. 1978 소수 찾기
*	@author	peter9378
*	@date		2018.03.15
*/
#include <iostream>
using namespace std;

// 에라토스테네스의 체
int arr[1001] = { 0, 1 };

// main
int main()
{
	ios::sync_with_stdio(false);
	// 입력받을 개수 입력
	int N;
	cin >> N;

	// 에라토스테네스의 체 적용
	for (int i = 2; i <= 1000; i++)
	{
		for (int j = 2; i*j <= 1000; j++)
			arr[i*j] = 1;
	}

	// 소수 카운트
	int answer = 0, temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (!arr[temp])
			answer++;
	}

	// 출력
	cout << answer;

	return 0;
}