/**
*	BOJ
*	No.9325	¾ó¸¶?
*	@author	peter9378
*	@date		2020.05.10
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

	int T;
	cin >> T;

	while (T--)
	{
		int s;
		cin >> s;

		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int q, p;
			cin >> q >> p;
			s += q * p;
		}
		cout << s << "\n";
	}

	return 0;
}