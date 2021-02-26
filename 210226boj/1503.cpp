/**
*	BOJ
*	No.1503	세 수 고르기
*	@author	peter9378
*	@date		2021.02.26
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

bool arr[1002];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;

		arr[temp] = true;
	}

	vector<int> v;
	for (int i = 1; i < 1002; i++)
	{
		if (!arr[i])
			v.push_back(i);
	}

	int answer = 2147483647;
	int len = v.size();
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			for (int k = 0; k < len; k++)
			{
				int q = v[i] * v[j] * v[k];
				if (abs(N - q) < answer)
					answer = abs(N - q);
				if (N + 1 < q)
					break;
			}
		}
	}
	cout << answer;

	return 0;
}
