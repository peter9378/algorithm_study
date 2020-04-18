/**
*	BOJ
*	No.2960	에라토스테네스의 체
*	@author	peter9378
*	@date		2020.04.18
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

bool arr[1001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	arr[0] = arr[1] = true;

	int index = 0;
	int answer = 0;
	while (!answer)
	{
		int P;
		for (int i = 2; i <= N; i++)
		{
			if (!arr[i])
			{
				P = i;
				break;
			}
		}

		for (int i = P; i <= N; i += P)
		{
			if (!arr[i])
			{
				if (++index == K)
					answer = i;
			}
			arr[i] = true;
		}
	}

	cout << answer;

	return 0;
}