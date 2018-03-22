/**
*	baekjoon_stepbystep
*	No. 2504 괄호의 값
*	@author	peter9378
*	@date		2018.03.23
*/
#include <iostream>
#include <string>
using namespace std;

// 스택 배열
char stack[100001];

// 간단한 스택 구현
class Stack {
private:
	int index;

public:
	Stack() {
		index = 0;
	}

	void push(char target) {
		if (index == 100000)
			return;
		stack[index] = target;
		index++;
		return;
	}

	void pop() {
		if (index == 0)
			return;
		index--;
		stack[index] = '0';
		return;
	}

	char top() {
		return stack[index - 1];
	}

	bool empty() {
		if (index == 0)
			return true;
		return false;
	}
};

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	int result = 0, temp = 1;
	Stack stk;

	// 연산 루프
	for (int i = 0; i < str.length(); i++)
	{
		switch (str[i])
		{
		case '(':
			temp *= 2;
			stk.push('(');
			break;
		case '[':
			temp *= 3;
			stk.push('[');
			break;
		case ')':
			if (str[i - 1] == '(')
				result += temp;
			if (stk.top() == '(')
				stk.pop();
			temp /= 2;
			break;
		case ']':
			if (str[i - 1] == '[')
				result += temp;
			if (stk.top() == '[')
				stk.pop();
			temp /= 3;
		}
	}

	// 출력
	if (stk.empty())
		cout << result;
	else
		cout << 0;

	return 0;
}