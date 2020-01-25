/**
*	BOJ
*	No.2607	비슷한 단어
*	@author	peter9378
*	@date		2020.01.26
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

map<char, int> m;

bool check(string target)
{
	map<char, int> tm;
	for (int i = 0; i < target.length(); i++)
		tm[target[i]]++;

	int diff = 0, a = 0, b = 0;
	for (char i = 'A'; i <= 'Z'; i++)
	{
		diff += abs((int)m[i] - (int)tm[i]);
		a += m[i];
		b += tm[i];
	}

	return diff < 3 && abs(a - b) < 2;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
		m[s[i]]++;

	int answer = 0;
	for (int i = 1; i < N; i++)
	{
		string temp;
		cin >> temp;

		if (check(temp))
			answer++;
	}

	cout << answer;

	return 0;
}
