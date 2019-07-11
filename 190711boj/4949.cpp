/**
*	BOJ
*	No.4949	균형잡힌 세상
*	@author	peter9378
*	@date		2019.07.11
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	while (getline(cin, s))
	{
		stack<int> st;
		if (s == ".")
			break;
		bool flag = true;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')
				st.push(s[i]);
			else if (s[i] == ')')
			{
				if (st.empty())
				{
					flag = false;
					break;
				}
				else
				{
					if (st.top() == '(')
						st.pop();
					else
					{
						flag = false;
						break;
					}
				}
			}

			if (s[i] == '[')
				st.push(s[i]);
			else if (s[i] == ']')
			{
				if (st.empty())
				{
					flag = false;
					break;
				}
				else
				{
					if (st.top() == '[')
						st.pop();
					else
					{
						flag = false;
						break;
					}
				}
			}
		}
		if (flag && st.empty())
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}
