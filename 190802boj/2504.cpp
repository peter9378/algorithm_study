/**
*	BOJ
*	No. 2504	괄호의 값
*	@author	peter9378
*	@date		2019.08.02
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	int result = 0, temp = 1;
	stack<int> stk;
	for (int i = 0; i < str.length(); i++)
	{
		switch (str[i])
		{
		case '(':
			temp *= 2;
			stk.push('(');
			break;
		case '[':
			temp *= 3;
			stk.push('[');
			break;
		case ')':
			if (i)
			{
				if (str[i - 1] == '(')
					result += temp;
				if (!stk.empty())
				{
					if (stk.top() == '(')
						stk.pop();
				}
				else
					stk.push(')');
			}
			else
				stk.push(')');
			temp /= 2;
			break;
		case ']':
			if (i)
			{
				if (str[i - 1] == '[')
					result += temp;
				if (!stk.empty())
				{
					if (stk.top() == '[')
						stk.pop();
				}
				else
					stk.push(']');
			}
			else
				stk.push(']');
			temp /= 3;
		}
	}

	

	if (stk.empty())
		cout << result;
	else
		cout << 0;

	return 0;
}