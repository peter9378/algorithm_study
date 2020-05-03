/**
*	BOJ
*	No.17211	좋은 날 싫은 날
*	@author	peter9378
*	@date		2020.05.03
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

double good[101];
double bad[101];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, condition;
	cin >> N >> condition;

	double gg, gb, bg, bb;
	cin >> gg >> gb >> bg >> bb;

	if (condition == 1)
	{
		good[0] = bg;
		bad[0] = bb;
	}
	else
	{
		good[0] = gg;
		bad[0] = gb;
	}

	for (int i = 1; i < N; i++)
	{
		good[i] = good[i - 1] * gg + bad[i - 1] * bg;
		bad[i] = good[i - 1] * gb + bad[i - 1] * bb;
	}

	cout << round(good[N - 1] * 1000) << "\n" << round(bad[N - 1] * 1000);

	return 0;
}