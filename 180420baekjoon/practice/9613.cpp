/**
*	baekjoon online judge
*	No. 9613	GCD 합
*	@author	peter9378
*	@date		2018.05.02
*/
#include <iostream>
using namespace std;

// 배열
int arr[101];

// gcd 함수
long long gcd(long long a, long long b)
{
	if (a%b)
		return gcd(b, a%b);
	else
		return b;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 테스트 케이스 개수 입력
	int T;
	cin >> T;

	// 테스트 케이스 루프
	while (T--)
	{
		long long sum = 0;

		// 숫자 개수 입력
		int N;
		cin >> N;

		// 숫자 입력
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		// 가능한 gcd 합을 모두 더함
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = i + 1; j < N; j++)
				sum += gcd(arr[i], arr[j]);
		}

		// 출력
		cout << sum << "\n";
	}

	return 0;
}