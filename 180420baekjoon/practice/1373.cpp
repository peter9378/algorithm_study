/**
*	baekjoon online judge
*	No. 1373	2진수 8진수
*	@author	peter9378
*	@date		2018.05.05
*/
#include <iostream>
#include <string.h>
using namespace std;

char arr[1000001];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> (arr+2);
	arr[0] = '0';
	arr[1] = '0';
	int length = strlen(arr);

	for(int i=length%3;i<length;i+=3)
		cout << (arr[i] - '0') * 4 + (arr[i + 1] - '0') * 2 + (arr[i + 2] - '0');

	return 0;
}