/**
*	BOJ
*	No.고급 레스토랑
*	@author	peter9378
*	@date		2020.04.28
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

	int a, b, c, d;
	cin >> a >> b >> c >> d;


	while (b > 0 && d > 0)
	{
		b -= c;
		d -= a;
	}

	if (b > 0)
		cout << "PLAYER A";
	else if (d > 0)
		cout << "PLAYER B";
	else
		cout << "DRAW";

	return 0;
}