/**
*	baekjoon online judge
*	No. 10995	별 찍기 - 20
*	@author	peter9378
*	@date		2019.03.28
*/
#include <iostream>
using namespace std;


// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		if (i % 2)
			cout << " ";
		for (int j = 0; j < N; j++)
			cout << "* ";
		cout << endl;
	}

	return 0;
}