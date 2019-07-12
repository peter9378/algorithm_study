/**
*	BOJ
*	No.2556	별 찍기 - 14
*	@author	peter9378
*	@date		2019.07.12
*/
#include <iostream>
#include <algorithm>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << "*";
		cout << "\n";
	}
	
	return 0;
}
