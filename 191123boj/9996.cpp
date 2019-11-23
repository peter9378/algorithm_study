/**
*	BOJ
*	No.9996	한국이 그리울 땐 서버에 접속하지
*	@author	peter9378
*	@date		2019.11.23
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

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	string s;
	cin >> s;

	for (int i = 0; i < N; i++)
	{
		string t;
		cin >> t;

		bool flag = false;
		int index;
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] != t[j])
			{
				t = t.substr(j);
				if (s[j] == '*')
					break;
				flag = true;
				break;
			}
		}

		if (flag)
		{
			cout << "NE\n";
			continue;
		}

		reverse(s.begin(), s.end());
		reverse(t.begin(), t.end());
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] != t[j])
			{
				if (s[j] == '*')
					break;
				flag = true;
				break;
			}
		}
		reverse(s.begin(), s.end());
		if (flag)
		{
			cout << "NE\n";
			continue;
		}

		cout << "DA\n";
	}

	return 0;
}
