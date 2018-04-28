/**
*	baekjoon online judge
*	No. 10845	ť
*	@author	peter9378
*	@date		2018.04.28
*/
#include <iostream>
#include <string>
using namespace std;

// ť �迭
int queue[10001];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

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
			cin >> queue[index];
			index++;
		}
		else if (input == "pop")
		{
			if (index == 0)
				cout << "-1\n";
			else
			{
				index--;
				cout << queue[0] << "\n";
				for (int j = 0; j < index; j++)
					queue[j] = queue[j + 1];
			}
		}
		else if (input == "size")
			cout << index << "\n";
		else if (input == "empty")
			cout << !(bool)index << "\n";
		else if (input == "front")
		{
			if (index == 0)
				cout << "-1\n";
			else
				cout << queue[0] << "\n";
		}
		else if (input == "back")
		{
			if (index == 0)
				cout << "-1\n";
			else
				cout << queue[index - 1] << "\n";
		}
		else
			cout << "what?";
	}

	return 0;
}