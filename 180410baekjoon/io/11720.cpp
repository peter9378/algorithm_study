/**
*	baekjoon online judge
*	No. 11720 숫자의 합
*	@author	peter9378
*	@date		2018.04.20
*/
#include <iostream>
#include <string>
using namespace std;

int ctoi(char a)
{
	return a - 48;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	string str;
	cin >> str;

	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += ctoi(str[i]);
	cout << sum;

	return 0;
}