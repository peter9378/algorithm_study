/**
*	baekjoon online judge
*	No. 10808	���ĺ� ����
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

	for (int i = 0; i < str.length(); i++)
		arr[str[i] - 97]++;

	for (int i = 0; i < 26; i++)
		cout << arr[i] << " ";

	return 0;
}