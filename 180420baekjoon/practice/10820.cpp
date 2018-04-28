/**
*	baekjoon online judge
*	No. 10820	���ڿ� �м�
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
		// �ʱⰪ
		int big = 0;
		int small = 0;
		int number = 0;
		int empty = 0;

		// �� �� �Է�
		getline(cin, str);
		
		// �Է��� ������ ���� Ż��
		if (str == "")
			break;

		// ���ڿ� ����
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

		// ���
		cout << small << " " << big << " " << number << " " << empty << "\n";
	}

	return 0;
}