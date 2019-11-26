/**
*	BOJ
*	No.1476	날짜 계산
*	@author	peter9378
*	@date		2019.11.26
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

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int E, S, M;
	cin >> E >> S >> M;

	for (int i = 1; i < 7981; i++)
	{
		if (i % 15 == E || (i % 15 == 0 && E == 15))
		{
			if (i % 28 == S || (i % 28 == 0 && S == 28))
			{
				if (i % 19 == M || (i % 19 == 0 && M == 19))
				{
					cout << i;
					break;
				}
			}
		}
	}

	return 0;
}
