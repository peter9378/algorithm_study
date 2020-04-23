/**
*	BOJ
*	No.1297	TV Å©±â
*	@author	peter9378
*	@date		2020.04.24
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

	int a, b, c;
	cin >> a >> b >> c;

	double x, y, z;
	x = sqrt(b*b + c * c);
	y = a * b / x;
	z = a * c / x;

	cout << (int)y << " " << (int)z;

	return 0;
}