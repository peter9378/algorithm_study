/**
*	BOJ
*	No.1252	이진수 덧셈
*	@author	peter9378
*	@date		2019.10.02
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	while (a.length() > b.length())
		b += '0';

	while (a.length() < b.length())
		a += '0';


	string answer = "";
	bool flag = false;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == '0' && b[i] == '0')
		{
			if (flag)
				answer += '1';
			else
				answer += '0';
			flag = false;
		}
		else if (a[i] == '1' && b[i] == '1')
		{
			if (flag)
				answer += '1';
			else
				answer += '0';
			flag = true;
		}
		else
		{
			if (flag)
			{
				answer += '0';
				flag = true;
			}
			else
			{
				answer += '1';
				flag = false;
			}
		}
	}
	if (flag)
		answer += '1';
	reverse(answer.begin(), answer.end());

	int temp = 0;
	while (answer[temp] == '0' && temp < answer.length())
		temp++;
	if (temp == answer.length())
		cout << 0;
	else
	{
		answer = answer.substr(temp);
		cout << answer;
	}

	return 0;
}