/**
*	BOJ
*	No.3009	네 번째 점
*	@author	peter9378
*	@date		2019.10.15
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	set<int> x;
	set<int> y;

	for (int i = 0; i < 3; i++)
	{
		int a, b;
		cin >> a >> b;

		if (x.find(a) == x.end())
			x.insert(a);
		else
			x.erase(a);
		if (y.find(b) == y.end())
			y.insert(b);
		else
			y.erase(b);
	}

	cout << *x.begin() << " " << *y.begin();

	return 0;
}