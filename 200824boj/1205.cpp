/**
*	BOJ
*	No.1205	등수 구하기
*	@author	peter9378
*	@date		2020.08.24
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
using namespace std;

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;
	int N, score, P;
	cin >> N >> score >> P;
	int answer = 1;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	if (N == P && v[N - 1] >= score)
		answer = -1;
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (v[i] > score)
				answer++;
		}
	}

	cout << answer;

	return 0;
}