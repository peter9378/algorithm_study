/**
*	baekjoon online judge
*	No. 11655	ROT13
*	@author	peter9378
*	@date		2018.05.01
*/
#include <iostream>
#include <string>
using namespace std;

// ROT13 변환
char rot(char target)
{
	if (target < 58)
		return target;
	if (target < 91)
	{
		if (target < 78)
			target += 13;
		else
			target -= 13;
	}
	else
	{
		if (target < 110)
			target += 13;
		else
			target -= 13;
	}
	return target;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 문자열 입력
	string str;
	getline(cin, str);

	// 출력
	for (int i = 0; i < str.length(); i++)
		cout << rot(str[i]);

	return 0;
}