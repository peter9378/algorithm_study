/**
*	BOJ
*	No.5543	상근날드
*	@author	peter9378
*	@date		2020.01.07
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

	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	cout << min(a, min(b, c)) + min(d, e) - 50;

	return 0;
}
