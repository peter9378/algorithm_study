/**
*	BOJ
*	No.14681	사분면 고르기
*	@author	peter9378
*	@date		2020.03.21
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

	int x, y;
	cin >> x >> y;

	if (x > 0)
	{
		if (y > 0)
			cout << 1;
		else
			cout << 4;
	}
	else
	{
		if (y > 0)
			cout << 2;
		else
			cout << 3;
	}

	return 0;
}