/**
*	BOJ
*	No.2812	크게 만들기
*	@author	peter9378
*	@date		2020.02.13
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

	int N, K;
	cin >> N >> K;

	string s;
	cin >> s;

	deque<char> dq;
	for (int i = 0; i < K; i++)
	{
		while (!dq.empty() && dq.back() < s[i])
			dq.pop_back();
		dq.push_back(s[i]);
	}

	for (int i = K; i < N; i++)
	{
		while (!dq.empty() && dq.back() < s[i])
			dq.pop_back();
		dq.push_back(s[i]);
		cout << dq.front();
		dq.pop_front();
	}

	return 0;
}
