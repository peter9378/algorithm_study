/**
*	BOJ
*	No.2167	2차원 배열의 합
*	@author	peter9378
*	@date		2019.11.02
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int arr[303][303];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
			arr[i][j] += arr[i - 1][j];
			arr[i][j] += arr[i][j - 1];
			arr[i][j] -= arr[i - 1][j - 1];
		}
	}

	int K;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << arr[c][d] + arr[a - 1][b - 1] - arr[a - 1][d] - arr[c][b - 1] << "\n";
	}

	return 0;
}