/**
*	baekjoon online judge
*	No. 9012	괄호
*	@author	peter9378
*	@date		2018.04.28
*/
#include <iostream>
#include <string>
using namespace std;

// 스택 배열
int stack[10001];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력 개수 입력
	int T;
	cin >> T;

	// 테스트 케이스 루프
	for (int test_case = 0; test_case < T; test_case++)
	{
		// 문자열 입력
		string str;
		cin >> str;

		int count = 0;
		for (int i = 0; i < str.length(); i++)
		{
			// 여는 괄호는 +1
			if (str[i] == '(')
				count++;
			// 닫는 괄호는 -1
			else
				count--;
			// count가 음수가 되면 이미 올바를 수 없음
			if (count < 0)
				break;
		}
		if (count)
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}