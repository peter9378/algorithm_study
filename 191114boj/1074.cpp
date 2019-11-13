/**
*	BOJ
*	No.1074	Z
*	@author	peter9378
*	@date		2019.11.14
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, r, c;
	cin >> N >> r >> c;

	int answer = 0;
	int x, y;
	x = y = pow(2, N) / 2;

	while (N--)
	{
		int temp = pow(2, N) / 2;
		int pass = pow(4, N);

		if (r < y && c < x)
		{
			x -= temp;
			y -= temp;
		}
		else if (r < y && x <= c)
		{
			x += temp;
			y -= temp;
			answer += pass;
		}
		else if (y <= r && c < x)
		{
			x -= temp;
			y += temp;
			answer += pass * 2;
		}
		else
		{
			x += temp;
			y += temp;
			answer += pass * 3;
		}
	}

	cout << answer;

	return 0;
}