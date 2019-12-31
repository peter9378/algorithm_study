/**
*	BOJ
*	No.11048	이동하기
*	@author	peter9378
*	@date		2020.01.01 - Hello 2020
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <cstring>
using namespace std;

int arr[1001][1001];

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
			arr[i][j] += max(arr[i - 1][j], max(arr[i][j - 1], arr[i - 1][j - 1]));
		}
	}

	cout << arr[N][M];

	return 0;
}
