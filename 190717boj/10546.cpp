/**
*	BOJ
*	No.10546	배부른 마라토너
*	@author	peter9378
*	@date		2019.07.17
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char answer[21];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	string temp;
	for (int i = 0; i < 2*N-1; i++)
	{
		cin >> temp;
		for (int j = 0; j < temp.length(); j++)
			answer[j] ^= temp[j];
	}
	
	cout << answer;
	return 0;
}
