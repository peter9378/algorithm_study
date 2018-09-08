/**
*	baekjoon online judge
*	No. 1016	Á¦°ö¤¤¤¤¼ö
*	@author	peter9378
*	@date		2018.09.09
*/
#include <iostream>
using namespace std;

long long int arr[1000001];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long int min, max;
	cin >> min >> max;

	long long int count = 0;
	for (long long int i = 2; i*i <= max; i++)
	{
		long long int isq = i * i;
		long long int temp = min / isq;
		if (min % isq)
			temp++;

		while (temp*isq <= max)
		{
			arr[temp*isq - min] = 1;
			temp++;
		}
	}

	for (long long int i = 0; i <= max - min; i++)
	{
		if (!arr[i])
			count++;
	}

	cout << count;

	return 0;
}