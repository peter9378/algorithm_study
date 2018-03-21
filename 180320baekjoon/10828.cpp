/**
*	baekjoon_stepbystep
*	No. 10828 스택
*	@author	peter9378
*	@date		2018.03.21
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
	// 명령 개수 입력
	int N;
	cin >> N;

	
	int index = 0;
	for (int i = 0; i < N; i++)
	{
		// 명령 받을 문자열
		string input;
		cin >> input;

		// 명령에 따라 처리
		if (input == "push")
		{
			cin >> stack[index];
			index++;
		}
		else if (input == "pop")
		{
			if (index == 0)
				cout << "-1" << "\n";
			else
			{
				index--;
				cout << stack[index] << "\n";
				stack[index] = 0;
			}
		}
		else if (input == "size")
			cout << index << "\n";
		else if (input == "empty")
		{
			if (index)
				cout << "0" << "\n";
			else
				cout << "1" << "\n";
		}
		else if (input == "top")
		{
			if (index == 0)
				cout << "-1" << "\n";
			else
				cout << stack[index - 1] << "\n";
		}
		else
			cout << "what?";
	}

	return 0;
}