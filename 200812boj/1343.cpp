/**
*	BOJ
*	No.1343	폴리오미노
*	@author	peter9378
*	@date		2020.08.12
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

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int idx = 0;

	while (idx < s.size())
	{
		if (s[idx] == '.')
		{
			idx++;
			continue;
		}

		int cnt = 0;
		int temp = idx;
		while (temp < s.size() && s[temp] == 'X')
		{
			temp++;
			cnt++;
		}

		if (cnt % 2 != 0)
		{
			cout << -1;
			return 0;
		}

		temp = idx;
		idx += cnt;
		while (cnt)
		{
			if (cnt >= 4)
			{
				s[temp] = 'A';
				s[temp + 1] = 'A';
				s[temp + 2] = 'A';
				s[temp + 3] = 'A';
				cnt -= 4;
				temp += 4;
			}
			else if (cnt == 2)
			{
				s[temp] = 'B';
				s[temp + 1] = 'B';
				cnt -= 2;
			}
		}
	}

	cout << s;

	return 0;
}