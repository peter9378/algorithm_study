/**
*	BOJ
*	No.4999	¾Æ!
*	@author	peter9378
*	@date		2019.12.01
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

bool arr[2002];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;
	if (a.length() < b.length())
		cout << "no";
	else
		cout << "go";

	return 0;
}
