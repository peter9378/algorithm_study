/**
*	baekjoon online judge
*	No. 10820	문자열 분석
*	@author	peter9378
*	@date		2018.04.28
*/
#include <iostream>
#include <string>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	while (true)
	{
		// 초기값
		int big = 0;
		int small = 0;
		int number = 0;
		int empty = 0;

		// 한 줄 입력
		getline(cin, str);
		
		// 입력이 없으면 루프 탈출
		if (str == "")
			break;

		// 문자열 루프
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
				empty++;
			else if (str[i] > 96)
				small++;
			else if (str[i] > 64)
				big++;
			else
				number++;
		}

		// 출력
		cout << small << " " << big << " " << number << " " << empty << "\n";
	}

	return 0;
}