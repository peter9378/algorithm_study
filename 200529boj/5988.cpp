/**
*	BOJ
*	No.5988	È¦¼öÀÏ±î Â¦¼öÀÏ±î
*	@author	peter9378
*	@date		2020.05.29
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

	int N;
	cin >> N;

	while (N--)
	{
		string s;
		cin >> s;

		if ((s.back() - '0') % 2)
			cout << "odd\n";
		else
			cout << "even\n";
	}

	return 0;
}