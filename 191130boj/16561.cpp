/**
*	BOJ
*	No.16561	3ÀÇ ¹è¼ö
*	@author	peter9378
*	@date		2019.11.29
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

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	n = (n / 3) - 3;
	cout << (n + 1)*(n + 2) / 2;

	return 0;
}
