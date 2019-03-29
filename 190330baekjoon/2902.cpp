/**
*	baekjoon online judge
*	No. 2902	KMP는 왜 KMP일까?
*	@author	peter9378
*	@date		2019.03.30
*/
#include <iostream>
#include <string>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	string str;
	cin >> str;

	cout << str[0];
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == '-')
			cout << str[i + 1];
	}

	return 0;
}