/**
*	baekjoon online judge
*	No. 10828 ����
*	@author	peter9378
*	@date		2018.04.28
*/
#include <iostream>
#include <string>
using namespace std;

// ���� �迭
int stack[10001];

// main
int main()
{
	ios::sync_with_stdio(false);
	// ��� ���� �Է�
	int N;
	cin >> N;

	int index = 0;
	for (int i = 0; i < N; i++)
	{
		// ��� ���� ���ڿ�
		string input;
		cin >> input;

		// ��ɿ� ���� ó��
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