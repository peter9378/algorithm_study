/**
*	BOJ
*	No.1004	¾î¸° ¿ÕÀÚ
*	@author	peter9378
*	@date		2019.12.10
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

bool check(int a, int b, int c, int d, int r)
{
	return (a - b)*(a - b) + (c - d)*(c - d) < r*r;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int x1, y1, x2, y2, n, answer = 0;
		cin >> x1 >> y1 >> x2 >> y2 >> n;
		for (int i = 0; i < n; i++)
		{
			int x, y, r;
			cin >> x >> y >> r;

			bool info1 = check(x, x1, y, y1, r);
			bool info2 = check(x, x2, y, y2, r);

			if (info1 ^ info2)
				answer++;
		}
		cout << answer << "\n";
	}

	return 0;
}