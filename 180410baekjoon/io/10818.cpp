/**
*	baekjoon online judge
*	No. 10818 최소, 최대
*	@date		2018.04.20
*/
#include <iostream>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int min = 1000001, max = -1000001;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp > max)
			max = temp;
		if (temp < min)
			min = temp;
	}

	cout << min << " " << max;

	return 0;
}