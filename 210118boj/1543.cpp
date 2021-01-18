/**
*	BOJ
*	No.1543	문서 검색
*	@author	peter9378
*	@date		2021.01.18
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
	string sub;
	getline(cin, s);
	getline(cin, sub);

	if (sub.length() > s.length())
		cout << 0;
	else
	{
		int answer = 0;
		for (int i = 0; i < s.length() - sub.length() + 1; i++)
		{
			bool flag = true;
			for (int j = 0; j < sub.length(); j++)
			{
				if (s[i + j] != sub[j])
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				answer++;
				i += sub.length() - 1;
			}
		}
		cout << answer;
	}

	return 0;
}
