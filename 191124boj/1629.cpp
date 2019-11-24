/**
*	BOJ
*	No.1629	°ö¼À
*	@author	peter9378
*	@date		2019.11.24
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

using namespace std;

long long p(int a, int b, int c)
{
	if (b == 1)
		return a;

	long long temp = p(a, b / 2, c);
	if (b % 2)
		return ((temp*temp) % c*a) % c;
	return (temp*temp) % c;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	cout << p(A%C, B, C);

	return 0;
}
