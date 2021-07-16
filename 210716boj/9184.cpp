/**
*	BOJ
*	No.9184	신나는 함수 실행
*	@author	peter9378
*	@date		2021.07.16
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

#define MAX 55

int a, b, c;
int dp[MAX][MAX][MAX];

int go(int x, int y, int z)
{
	if (x <= 0 || y <= 0 || z <= 0)
		return 1;

	int& result = dp[x][y][z];
	if (result != -1)
		return result;

	if (x > 20 || y > 20 || z > 20)
		return result = go(20, 20, 20);
	if (x < y && y < z)
		return result = go(x, y, z - 1) + go(x, y - 1, z - 1) - go(x, y - 1, z);

	return result = go(x - 1, y, z) + go(x - 1, y - 1, z) + go(x - 1, y, z - 1) - go(x - 1, y - 1, z - 1);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));
	while (1) {
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)
			break;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << go(a, b, c) << "\n";
	}

	return 0;
}
