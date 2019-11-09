/**
*	BOJ
*	No.2501	약수 구하기
*	@author	peter9378
*	@date		2019.11.09
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	set<int> answer;
	for (int i = 1; i * i <= N; i++)
	{
		if (N%i == 0)
			answer.insert(i);
	}

	vector<int> v(answer.begin(), answer.end());

	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i] * v[i] == N)
			continue;
		v.push_back(N / v[i]);
	}

	if (K > v.size()) cout << 0;
	else cout << v[K - 1];

	return 0;
}