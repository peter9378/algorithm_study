/**
*	BOJ
*	No.2530	인공지능 시계
*	@author	peter9378
*	@date		2019.11.22
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

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int h, m, s;
	cin >> h >> m >> s;

	int total = h * 3600 + m * 60 + s;
	int D;
	cin >> D;
	total += D;
	total %= 86400;

	cout << total / 3600 << " " << total % 3600 / 60 << " " << total % 60;

	return 0;
}
