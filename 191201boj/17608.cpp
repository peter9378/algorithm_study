/**
*	BOJ
*	No.17608	¸·´ë±â
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

	int answer = 1;
	int current = v.back();
	for (int i = v.size() - 2; i > -1; i--)
	{
		if (v[i] > current)
		{
			answer++;
			current = v[i];
		}
	}
	cout << answer;

	return 0;
}
