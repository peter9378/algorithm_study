/**
*	BOJ
*	No.2863	이게 분수?
*	@author	peter9378
*	@date		2019.12.11
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
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	double A, B, C, D;
	cin >> A >> B >> C >> D;

	double result = max((A + B) / (C + D), max((C + A) / (D + B), max((D + C) / (B + A), (B + D) / (A + C))));

	if ((A + B) / (C + D) == result)
		cout << 0;
	else if ((C + A) / (D + B) == result)
		cout << 1;
	else if ((D + C) / (B + A) == result)
		cout << 2;
	else
		cout << 3;

	return 0;
}
