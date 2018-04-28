/**
*	baekjoon online judge
*	No. 10808	알파벳 개수
*	@author	peter9378
*	@date		2018.04.28
*/
#include <iostream>
#include <string>
using namespace std;

// 알파벳 배열
int arr[26];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 문자열 입력
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
		arr[str[i] - 97]++;

	for (int i = 0; i < 26; i++)
		cout << arr[i] << " ";

	return 0;
}