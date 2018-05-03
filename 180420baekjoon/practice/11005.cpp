/**
*	baekjoon online judge
*	No. 11005	진법 변환 2
*	@author	peter9378
*	@date		2018.05.03
*/
#include <iostream>
using namespace std;

int arr[101];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, B;
	cin >> N >> B;

	int i = 0;
	while (N != 0)
	{
		arr[i] = N%B;
		N /= B;
		i++;
	}
	i--;

	char t = 'A';
	for (; i >= 0; i--)
	{
		if (arr[i] >= 10)
		{
			for (int j = 10; j <= 35; j++)
			{
				if (arr[i] == j)
					cout << t;
				t++;
			}
		}
		else
			cout << arr[i];
		t = 'A';
	}

	return 0;
}