/**
*	BOJ
*	No.1371	가장 많은 글자
*	@author	peter9378
*	@date		2019.12.03
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

int arr[26];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	while (cin >> s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				arr[s[i] - 'a']++;
		}
		s.clear();
	}
	int maxi = 0;
	for (int i = 0; i < 26; i++)
		maxi = max(maxi, arr[i]);

	for (int i = 0; i < 26; i++)
	{
		if (arr[i] == maxi)
			cout << (char)(i + 'a');
	}

	return 0;
}
