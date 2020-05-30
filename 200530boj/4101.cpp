/**
*	BOJ
*	No.4101	Å©³Ä?
*	@author	peter9378
*	@date		2020.05.30
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

	int a, b;
	while (true)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;

		cout << (a > b ? "Yes\n" : "No\n");
	}

	return 0;
}