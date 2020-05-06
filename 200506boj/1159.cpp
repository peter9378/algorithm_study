/**
*	BOJ
*	No.1159	³ó±¸ °æ±â
*	@author	peter9378
*	@date		2020.05.06
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

int arr[26];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int maxi = 0;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		arr[s[0] - 'a']++;
		maxi = max(maxi, arr[s[0] - 'a']);
	}

	if (maxi > 4)
	{
		for (int i = 0; i < 26; i++)
		{
			if (arr[i] > 4)
				cout << char('a' + i);
		}
	}
	else
		cout << "PREDAJA";

	return 0;
}