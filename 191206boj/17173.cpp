/**
*	BOJ
*	No.17173	배수들의 합
*	@author	peter9378
*	@date		2019.12.06
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

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> v(M);
	for (int i = 0; i < M; i++)
		cin >> v[i];

	long long answer = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i%v[j] == 0)
			{
				answer += i;
				break;
			}
		}
	}

	cout << answer;

	return 0;
}
