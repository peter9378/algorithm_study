/**
*	baekjoon online judge
*	No. 10809	알파벳 찾기
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

	// -1로 배열 초기화
	for (int i = 0; i < 26; i++)
		arr[i] = -1;

	// -1인 경우에만 index 대입(중복 제거)
	for (int i = 0; i < str.length(); i++)
	{
		if (arr[str[i] - 97] == -1)
			arr[str[i] - 97] = i;
	}

	// 출력
	for (int i = 0; i < 26; i++)
		cout << arr[i] << " ";

	return 0;
}