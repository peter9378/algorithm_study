/**
*	BOJ
*	No.10870	피보나치 수 5
*	@author	peter9378
*	@date		2019.11.06
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int arr[21];

int fibo(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	if (arr[n] == 0)
		return fibo(n - 1) + fibo(n - 2);
	return arr[n];
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	cout << fibo(N);

	return 0;
}