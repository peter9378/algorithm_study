/**
*	BOJ
*	No.9494	Text Roll
*	@author	peter9378
*	@date		2020.05.21
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
#include <cstring>
#include <iterator>
#include <numeric>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		int n;
		cin >> n;

		if (n == 0)
			break;

		int answer = 0;
		for (int i = 0; i <= n; i++)
		{
			string s;
			getline(cin, s);

			if (answer > s.length())
				continue;

			for (int j = answer; j < s.length(); j++)
			{
				if (s[j] == ' ')
					break;
				answer++;
			}
		}
		cout << answer + 1 << "\n";
	}

	return 0;
}