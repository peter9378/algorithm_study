/**
*	BOJ
*	No.1759	암호 만들기
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

bool is_fine(string s)
{
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] < s[i - 1])
			return false;
	}
	bool flag = false;
	int count = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			flag = true;
		else
			count++;
	}
	if (count < 2)
		return false;
	return flag;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int L, C;
	cin >> L >> C;

	vector<char> v;
	for (int i = 0; i < C; i++)
	{
		char c;
		cin >> c;
		v.push_back(c);
	}
	vector<int> check;
	for (int i = 0; i < L; i++)
		check.push_back(1);
	for (int i = L; i < C; i++)
		check.push_back(0);

	sort(v.begin(), v.end());
	sort(check.begin(), check.end());
	set<string> ss;
	do
	{
		string s = "";
		for (int i = 0; i < C; i++)
		{
			if (check[i])
				s += v[i];
		}
		if (is_fine(s))
			ss.insert(s);

	} while (next_permutation(check.begin(), check.end()));

	for (auto iter = ss.begin(); iter != ss.end(); iter++)
		cout << *iter << "\n";

	return 0;
}