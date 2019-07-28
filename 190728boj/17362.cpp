/**
*	BOJ
*	No.17362	수학은 체육과목 입니다2
*	@author	peter9378
*	@date		2019.07.28
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s = "12345432";
	int n;
	cin >> n;
	cout << s[(n - 1) % 8];

	return 0;
}