/**
*	BOJ
*	No.1598	꼬리를 무는 숫자 나열
*	@author	peter9378
*	@date		2020.06.06
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
	cin >> a >> b;

	cout << abs((a - 1) / 4 - (b - 1) / 4) + abs((a - 1) % 4 - (b - 1) % 4);

	return 0;
}