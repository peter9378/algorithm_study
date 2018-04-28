/**
*	baekjoon online judge
*	No. 10809	���ĺ� ã��
*	@author	peter9378
*	@date		2018.04.28
*/
#include <iostream>
#include <string>
using namespace std;

// ���ĺ� �迭
int arr[26];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// ���ڿ� �Է�
	string str;
	cin >> str;

	// -1�� �迭 �ʱ�ȭ
	for (int i = 0; i < 26; i++)
		arr[i] = -1;

	// -1�� ��쿡�� index ����(�ߺ� ����)
	for (int i = 0; i < str.length(); i++)
	{
		if (arr[str[i] - 97] == -1)
			arr[str[i] - 97] = i;
	}

	// ���
	for (int i = 0; i < 26; i++)
		cout << arr[i] << " ";

	return 0;
}