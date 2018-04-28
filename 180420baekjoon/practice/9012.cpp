/**
*	baekjoon online judge
*	No. 9012	��ȣ
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
	cin.tie(NULL);

	// �Է� ���� �Է�
	int T;
	cin >> T;

	// �׽�Ʈ ���̽� ����
	for (int test_case = 0; test_case < T; test_case++)
	{
		// ���ڿ� �Է�
		string str;
		cin >> str;

		int count = 0;
		for (int i = 0; i < str.length(); i++)
		{
			// ���� ��ȣ�� +1
			if (str[i] == '(')
				count++;
			// �ݴ� ��ȣ�� -1
			else
				count--;
			// count�� ������ �Ǹ� �̹� �ùٸ� �� ����
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