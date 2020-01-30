/**
*	BOJ
*	No.1100	го╬А д╜
*	@author	peter9378
*	@date		2020.01.29
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
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int answer = 0;
	for (int i = 0; i < 4; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < 8; j += 2)
		{
			if (s[j] == 'F')
				answer++;
		}

		cin >> s;
		for (int j = 1; j < 8; j += 2)
		{
			if (s[j] == 'F')
				answer++;
		}
	}

	cout << answer;

	return 0;
}
