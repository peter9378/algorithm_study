/**
*	BOJ
*	No.1577	도로의 개수
*	@author	peter9378
*	@date		2021.07.27
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
#include <unordered_map>
#include <cstring>
#include <iterator>
#include <numeric>
#include <complex>
using namespace std;

int direction_x[2] = { 1,0 }, direction_y[2] = { 0,1 };

int N, M, K;
int arr[101][101][2];
long long dp[101][101];

long long go(int x, int y)
{
	if (x == N && y == M)
		return 1;

	long long& result = dp[x][y];
	if (result != -1)
		return result;

	result = 0;
	for (int i = 0; i < 2; i++)
	{
		if (!arr[x][y][i]) {
			int next_x = x + direction_x[i];
			int next_y = y + direction_y[i];
			if (next_x <= N && next_y <= M)
				result += go(next_x, next_y);
		}
	}

	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	while (K--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		if (a > c)
			swap(a, c);
		else if (b > d)
			swap(b, d);

		if (a < c)
			arr[a][b][0] = 1;
		else if (b < d)
			arr[a][b][1] = 1;
	}

	memset(dp, -1, sizeof(dp));
	cout << go(0, 0);

	return 0;
}
