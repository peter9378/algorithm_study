/**
*	BOJ
*	No.5063	TGN
*	@author	peter9378
*	@date		2020.01.26
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

	int N;
	cin >> N;

	while (N--)
	{
		int r, e, c;
		cin >> r >> e >> c;

		if (r < e - c)
			cout << "advertise\n";
		else if (r > e - c)
			cout << "do not advertise\n";
		else
			cout << "does not matter\n";
	}

	return 0;
}
