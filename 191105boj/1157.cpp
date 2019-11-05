/**
*	BOJ
*	No.1157	단어 공부
*	@author	peter9378
*	@date		2019.11.05
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	map<char, int> m;
	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i] > 96 ? s[i] - 32 : s[i];
		if (m.find(c) != m.end())
			m[c]++;
		else
			m[c] = 1;
	}

	int answer = -1;
	for (auto iter = m.begin(); iter != m.end(); iter++)
		answer = max(answer, iter->second);

	int count = 0;
	for (auto iter = m.begin(); iter != m.end(); iter++)
	{
		if (iter->second == answer)
			count++;
	}

	if (count > 1)
		cout << "?";
	else
	{
		for (auto iter = m.begin(); iter != m.end(); iter++)
		{
			if (iter->second == answer)
			{
				cout << iter->first;
				break;
			}
		}
	}

	return 0;
}