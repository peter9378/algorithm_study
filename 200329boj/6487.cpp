/**
*	BOJ
*	No.6487	두 직선의 교차 여부
*	@author	peter9378
*	@date		2020.03.29
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

	int x[4], y[4];
	while (N--)
	{
		for (int i = 0; i < 4; i++)
			cin >> x[i] >> y[i];
		double a = x[1] - x[0], b = y[1] - y[0], c = x[3] - x[2], d = y[3] - y[2];

		if (a*d - b * c)
		{
			double r = (d*(x[2] - x[0]) - c * (y[2] - y[0])) / (a*d - b * c);
			printf("POINT %.2lf %.2lf\n", a*r + x[0], b*r + y[0]);
		}
		else
			cout << (x[2] - x[0])*b - (y[2] - y[0])*a ? "NONE" : "LINE";
	}

	return 0;
}