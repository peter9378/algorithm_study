/**
*	BOJ
*	No.1550	16Áø¼ö
*	@author	peter9378
*	@date		2021.04.29
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

	int answer = 0;
	for (int i = 0; i < s.length(); i++)
	{
		answer *= 16;

		if (s[i] >= 'A' && s[i] <= 'F')
			answer += s[i] - 'A' + 10;
		else
			answer += s[i] - '0';
	}
	cout << answer;

	return 0;
}
