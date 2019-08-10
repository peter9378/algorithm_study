/**
*	BOJ
*	No.2740	행렬 곱셈
*	@author	peter9378
*	@date		2019.08.10
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[101][101];
int arrr[101][101];
int answer[101][101];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	int K;
	cin >> M >> K;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
			cin >> arrr[i][j];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			for (int k = 0; k < M; k++)
				answer[i][j] += arr[i][k] * arrr[k][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
			cout << answer[i][j] << " ";
		cout << "\n";
	}


	

	return 0;
}