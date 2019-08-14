/**
*	BOJ
*	No.2884	알람 시계
*	@author	peter9378
*	@date		2019.08.14
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int h, m;
	cin >> h >> m;

	int total = h * 60 + m;
	if (total < 45)
		cout << 23 << " " << m + 15;
	else
	{
		total -= 45;
		cout << total / 60 << " " << total % 60;
	}

	return 0;
}