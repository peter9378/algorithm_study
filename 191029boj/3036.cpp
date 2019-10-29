/**
*	BOJ
*	No.3036	¸µ
*	@author	peter9378
*	@date		2019.10.29
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int gcd(int a, int b)
{
	if (a < b)
		swap(a, b);

	int result;
	while (b != 0)
	{
		result = a % b;
		a = b;
		b = result;
	}
	return a;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int K;
	cin >> K;

	for (int i = 1; i < N; i++)
	{
		int temp;
		cin >> temp;

		int g = gcd(K, temp);
		cout << K / g << "/" << temp / g << "\n";
	}

	return 0;
}