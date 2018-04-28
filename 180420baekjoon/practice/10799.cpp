/**
*	baekjoon online judge
*	No. 10799	쇠막대기
*	@author	peter9378
*	@date		2018.04.28
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 문자열 입력
	string str;
	cin >> str;

	stack<char> stk;
	int answer = 0;
	for (int i = 0; i < str.length(); i++)
	{
		// 여는 괄호는 무조건 저장
		if (str[i] == '(')
			stk.push('(');
		else
		{
			// 닫는 괄호면 일단 pop
			stk.pop();

			// 이전 괄호가 여는 괄호였으면 레이저. 스택 크기와 나무토막 수가 같으므로 스택 크기를 더해줌
			if (str[i - 1] == '(')
				answer += stk.size();
			// 아니면 나무 끝이니까 1만 더해줌
			else
				answer++;
		}
	}

	// 출력
	cout << answer;

	return 0;
}