/**
*	BOJ
*	No.1940	аж╦Ы
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

	int N;
	cin >> N;

	vector<int> v(N);
	int M;
	cin >> M;
	int answer = 0;

	unordered_set<int> s(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		if (s.find(v[i]) == s.end())
			s.insert(M - v[i]);
		else
			answer++;
	}

	cout << answer;

	return 0;
}
