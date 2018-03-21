/**
*	baekjoon_stepbystep
*	No. 10828 스택
*	@author	peter9378
*	@date		2018.03.21
*/
#include <iostream>
#include <string>
using namespace std;

// 입력 수열 배열
int input[100001];
// 스택 배열
int stack[100001];
// 출력 배열
char output[200002];

class Stack {
private:
	int index;

public:
	Stack() {
		index = 0;
	}
	void push(int target) {
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
		stack[index] = 0;
		return;
	}
	int top() {
		return stack[index - 1];
	}
};

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// 명령 개수 입력
	int N;
	cin >> N;

	// 수열 입력
	for (int i = 0; i < N; i++)
		cin >> input[i];

	Stack stk;
	int index = 0;
	for (int i = 0, j=1; i < N; i++)
	{
		while (input[i] > stk.top())
		{
			stk.push(j);
			output[index] = '+';
			j++;
			index++;
		}
		if (input[i] == stk.top())
		{
			stk.pop();
			output[index] = '-';
			index++;
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
	index = 0;
	while (output[index])
	{
		cout << output[index] << "\n";
		index++;
	}

	return 0;
}