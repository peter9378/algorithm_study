/**
*	BOJ
*	No.3613	Java vs C++
*	@author	peter9378
*	@date		2021.03.10
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
#include <unordered_map>
#include <cstring>
#include <iterator>
#include <numeric>
#include <complex>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	bool cpp = false;
	bool java = false;
	bool flag = false;
	string answer;

	for (int i = 0; i < s.length(); i++)
	{
		if ('A' <= s[i] && s[i] <= 'Z')
		{
			if (!i || cpp)
			{
				flag = true;
				break;
			}

			answer += '_';
			answer += s[i] - 'A' + 'a';
			java = true;
		}
		else if (s[i] == '_')
		{
			if (!i || java || i == s.length() - 1 || s[i + 1] == '_' || ('A' <= s[i + 1] && s[i + 1] <= 'Z'))
			{
				flag = true;
				break;
			}

			answer += s[i + 1] - 'a' + 'A';
			i++;
			cpp = true;
		}
		else
			answer += s[i];
	}

	cout << (flag ? "Error!" : answer);

	return 0;
}
