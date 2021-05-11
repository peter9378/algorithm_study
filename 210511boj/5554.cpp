/**
*	BOJ
*	No.5554	심부름 가는 길
*	@author	peter9378
*	@date		2021.05.11
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

	int time = a + b + c + d;
	cout << time / 60 << "\n" << time % 60;

	return 0;
}
