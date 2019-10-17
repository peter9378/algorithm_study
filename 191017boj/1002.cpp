/**
*	BOJ
*	No.1002	≈Õ∑ø
*	@author	peter9378
*	@date		2019.10.17
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getDistance(int x1, int y1, int x2, int y2)
{
	return pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		int distance = getDistance(x1, y1, x2, y2);
		if (x1 == x2 && y1 == y2 && r1 == r2)
			cout << "-1\n";
		else if (distance == pow((r1 + r2), 2))
			cout << "1\n";
		else if (distance == pow(abs(r1 - r2), 2) && distance)
			cout << "1\n";
		else if (distance > pow((r1 + r2), 2))
			cout << "0\n";
		else if (distance < pow(abs(r1 - r2), 2))
			cout << "0\n";
		else
			cout << "2\n";
	}

	return 0;
}