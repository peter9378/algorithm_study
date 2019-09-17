/**
*	BOJ
*	No.1764	듣보잡
*	@author	peter9378
*	@date		2019.09.17
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	set<string> answer;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		answer.insert(s);
	}

	vector<string> v;
	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		if (answer.find(s) != answer.end())
			v.push_back(s);
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}