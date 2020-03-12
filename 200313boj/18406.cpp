/**
*	BOJ
*	No.18406	럭키 스트레이트
*	@author	peter9378
*	@date		2020.03.13
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

	string s;
	cin >> s;

	int sum = 0;
	for (int i = 0; i < s.length() / 2; i++)
		sum += (s[i] - '0');
	for (int i = s.length() / 2; i < s.length(); i++)
		sum -= (s[i] - '0');

	if (sum)
		cout << "READY";
	else
		cout << "LUCKY";

	return 0;
}
