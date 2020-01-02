/**
*	BOJ
*	No.10569	¥Ÿ∏È√º
*	@author	peter9378
*	@date		2020.01.02
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

	int T;
	cin >> T;

	while (T--)
	{
		int a, b;
		cin >> a >> b;
		cout << b - a + 2 << "\n";
	}

	return 0;
}
