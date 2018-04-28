/**
*	baekjoon online judge
*	No. 10866	덱
*	@author	peter9378
*	@date		2018.04.28
*/
#include <iostream>
#include <string>
using namespace std;

// 덱 배열
int dequeue[10001];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

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
		if (input == "push_front")
		{
			for (int j = index; j > 0; j--)
				dequeue[j] = dequeue[j - 1];
			cin >> dequeue[0];
			index++;
		}
		else if (input == "push_back")
		{
			cin >> dequeue[index];
			index++;
		}
		else if (input == "pop_front")
		{
			if (index == 0)
				cout << "-1\n";
			else
			{
				index--;
				cout << dequeue[0] << "\n";
				for (int j = 0; j < index; j++)
					dequeue[j] = dequeue[j + 1];
			}
		}
		else if (input == "pop_back")
		{
			if (index == 0)
				cout << "-1\n";
			else
			{
				index--;
				cout << dequeue[index] << "\n";
				dequeue[index] = 0;
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
				cout << dequeue[0] << "\n";
		}
		else if (input == "back")
		{
			if (index == 0)
				cout << "-1\n";
			else
				cout << dequeue[index - 1] << "\n";
		}
		else
			cout << "what\n";
	}

	return 0;
}