/**
*	baekjoon online judge
*	No. 10799	�踷���
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

	// ���ڿ� �Է�
	string str;
	cin >> str;

	stack<char> stk;
	int answer = 0;
	for (int i = 0; i < str.length(); i++)
	{
		// ���� ��ȣ�� ������ ����
		if (str[i] == '(')
			stk.push('(');
		else
		{
			// �ݴ� ��ȣ�� �ϴ� pop
			stk.pop();

			// ���� ��ȣ�� ���� ��ȣ������ ������. ���� ũ��� �����丷 ���� �����Ƿ� ���� ũ�⸦ ������
			if (str[i - 1] == '(')
				answer += stk.size();
			// �ƴϸ� ���� ���̴ϱ� 1�� ������
			else
				answer++;
		}
	}

	// ���
	cout << answer;

	return 0;
}