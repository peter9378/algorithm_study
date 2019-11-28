/**
*	BOJ
*	No.1009	분산처리
*	@author	peter9378
*	@date		2019.11.28
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

		int aa = a;
		for (int i = 0; i < b - 1; i++)
			a = aa * a % 10;
		if (a)
			cout << a << "\n";
		else
			cout << "10\n";
	}

	return 0;
}
