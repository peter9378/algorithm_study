/**
*	sw Expert Academy
*	No. 1206 1차원 배열 연습 문제
*	@author	peter9378
*	@date		2018.03.20
*/
#include <iostream>
using namespace std;

int arr[1001];
int check[4] = { -2, -1, 1, 2 };

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	// 테스트 케이스 개수 입력

	int T = 10;
	int N;
	while(T--)
	{
		int sum = 0;
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> arr[i];

		int max_number = 0;
		for (int i = 2; i < N - 1; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int temp = i + check[j];
				max_number = max(max_number, arr[temp]);
			}
			sum += (arr[i] > max_number) ? arr[i] - max_number : 0;
		}

		cout << "#" << 10-T << " " << sum << "\n";
	}

	return 0;
}