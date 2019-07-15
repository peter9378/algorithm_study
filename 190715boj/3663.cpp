/**
*	BOJ
*	No.3663	고득점
*	@author	peter9378
*	@date		2019.07.15
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int min(int a, int b)
{
	return a > b ? b : a;
}

bool isDone(string target)
{
	for (int i = 0; i < target.length(); i++)
	{
		if (target[i] != 'A')
			return false;
	}
	return true;
}

int getNearIndex(string target, int index)
{
	int temp = 1;
	while (true)
	{
		if (isDone(target))
			return -1;
		if (index + temp < target.length())
		{
			if (target[index + temp] != 'A')
				return index + temp;
		}
		else if (index + temp >= target.length())
		{
			if (target[index + temp - target.length()] != 'A')
				return index + temp - target.length();
		}
		if (index >= temp)
		{
			if (target[index - temp] != 'A')
				return index - temp;
		}
		else if (index < temp)
		{
			if (target[index - temp + target.length()] != 'A')
				return index - temp + target.length();
		}
		temp++;
	}
	return isDone(target);
}

int solution(string name) {
	int answer = 0;
	bool flag = true;
	for (int i = 0; i < name.length(); i++)
	{
		if (name[i] != 'A')
		{
			flag = false;
			break;
		}
	}
	if (flag)
		return 0;

	for (int i = 0; i < name.length(); i++)
	{
		answer += min(name[i] - 65, 91 - name[i]);
	}

	int temp = name.length();
	for (int i = 0; i < name.length(); i++)
	{
		int j = i + 1;
		while (i != j && name[j] == 'A')
			j = (j + 1) % name.length();
		temp = min(temp, i + (name.length() + i - j) % name.length());
	}

	reverse(name.begin() + 1, name.end());
	for (int i = 0; i < name.length(); i++)
	{
		int j = i + 1;
		while (i != j && name[j] == 'A')
			j = (j + 1) % name.length();
		temp = min(temp, i + (name.length() + i - j) % name.length());
	}

	return answer + temp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		string s;
		cin >> s;

		cout << solution(s) << "\n";
	}
	return 0;
}