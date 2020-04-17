/**
*	BOJ
*	No.1302	º£½ºÆ® ¼¿·¯
*	@author	peter9378
*	@date		2020.04.17
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

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	map<string, int> m;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		m[s]++;
	}

	string answer;
	int most = -1;
	for (auto iter = m.begin(); iter != m.end(); iter++)
	{
		if (iter->second > most)
		{
			answer = iter->first;
			most = iter->second;
		}
	}

	cout << answer;

	return 0;
}