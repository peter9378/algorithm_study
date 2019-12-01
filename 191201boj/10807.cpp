/**
*	BOJ
*	No.10807	개수 세기
*	@author	peter9378
*	@date		2019.12.01
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
	for (int i = 0; i < N; i++)
		cin >> v[i];

	int V;
	cin >> V;

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		if (v[i] == V)
			answer++;
	}
	cout << answer;

	return 0;
}
