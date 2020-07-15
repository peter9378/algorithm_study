/**
*	BOJ
*	No.1259	ÆÓ¸°µå·Ò¼ö
*	@author	peter9378
*	@date		2020.07.15
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
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	while (cin >> s)
	{
		if (s == "0")
			break;

		bool flag = true;
		for (int i = 0; i < s.length() / 2; i++)
		{
			if (s[i] != s[s.length() - i - 1])
			{
				flag = false;
				break;
			}
		}

		if (flag)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}