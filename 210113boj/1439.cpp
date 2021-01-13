/**
*	BOJ
*	No.1439	µÚÁý±â
*	@author	peter9378
*	@date		2021.01.13
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

	int zero = 0, one = 0;
	if (s[0] == '0')
		zero++;
	else
		one++;

	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] != s[i - 1])
		{
			if (s[i] == '0')
				zero++;
			else
				one++;
		}
	}

	cout << min(zero, one);

	return 0;
}
