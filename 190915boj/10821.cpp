/**
*	BOJ
*	No.10821	정수의 개수
*	@author	peter9378
*	@date		2019.09.15
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	cout << count(s.begin(), s.end(), ',') + 1;

	return 0;
}