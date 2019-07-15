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

	int curIndex = 0;
	while (!isDone(name))
	{
		if (name[curIndex] != 'A')
		{
			answer += min(name[curIndex] - 65, 91 - name[curIndex]);
			name[curIndex] = 'A';
			int temp = getNearIndex(name, curIndex);
			if(temp != -1)
				answer += abs(min(temp - curIndex, curIndex - temp+ name.length()));
			curIndex = temp;
		}
		else
		{
			int temp = getNearIndex(name, curIndex);
			answer += min(temp - answer, answer - temp + name.length());
			curIndex = temp;
		}
	}
	return answer;
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