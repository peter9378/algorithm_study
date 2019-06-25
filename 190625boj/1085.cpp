/**
*	BOJ
*	No.1085	직사각형에서 탈출
*	@author	peter9378
*	@date		2019.06.25	- Remember 6.25 -
*/
#include <iostream>
#include <algorithm>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	cout << min(min(x, w - x), min(y, h - y));

	return 0;
}