/**
*	baekjoon online judge
*	No. 10953 A+B-6
*	@author	peter9378
*	@date		2018.04.19
*/
#include <iostream>
#include <string>
using namespace std;

int stoi(char s)
{
	return s - 48;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string str;
	int T;
	cin >> T;

	while (T--)
	{
		cin >> str;
		cout << stoi(str[0]) + stoi(str[2]) << "\n";
	}

	return 0;
}