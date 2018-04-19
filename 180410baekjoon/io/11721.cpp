/**
*	baekjoon online judge
*	No. 11721 열 개씩 끊어 출력하기
*	@author	peter9378
*	@date		2018.04.20
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (i % 10 == 0 && i != 0)
			cout << "\n";
		cout << str[i];
	}

	return 0;
}