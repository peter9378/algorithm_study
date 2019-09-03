/**
*	BOJ
*	No.1712	손익분기점
*	@author	peter9378
*	@date		2019.09.04
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	if (B >= C)
		cout << -1;
	else
		cout << A / (C - B) + 1;

	return 0;
}