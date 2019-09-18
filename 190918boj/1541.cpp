/**
*	BOJ
*	No.1541	잃어버린 괄호
*	@author	peter9378
*	@date		2019.09.18
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int get_sum(string s)
{
	string tmp = "";
	int result = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '+')
		{
			result += stoi(tmp);
			tmp = "";
		}
		else
			tmp += s[i];
	}
	result += stoi(tmp);
	return result;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int answer = 0;
	string temp = "";
	bool flag = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '-')
		{
			if (flag)
				answer -= get_sum(temp);
			else
				answer += get_sum(temp);
			flag = true;
			temp = "";
		}
		else if (s[i] == '+')
		{
			temp += s[i];
		}
		else
			temp += s[i];
	}

	if (s.length() - temp.length() > 0)
	{
		if (s[s.length() - temp.length() - 1] == '-')
			answer -= get_sum(temp);
	}
	else
		answer += get_sum(temp);
	cout << answer;

	return 0;
}