/**
*	BOJ
*	No.11660	구간 합 구하기 2
*	@author	peter9378
*	@date		2020.06.23
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
#include <iterator>
#include <numeric>
using namespace std;

int arr[1033][1033];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			arr[i + 1][j + 1] = arr[i + 1][j] + arr[i][j + 1] - arr[i][j] + a;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << arr[c][d] - arr[a - 1][d] - arr[c][b - 1] + arr[a - 1][b - 1] << "\n";
	}

	return 0;
}
