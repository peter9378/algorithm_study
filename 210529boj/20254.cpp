/**
*	BOJ
*	No.20254	Site Score
*	@author	peter9378
*	@date		2021.05.29
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
#include <unordered_map>
#include <cstring>
#include <iterator>
#include <numeric>
#include <complex>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << a * 56 + b * 24 + c * 14 + d * 6;

	return 0;
}
