/**
*	BOJ
*	No.2749	피보나치 수 3
*	@author	peter9378
*	@date		2020.02.14
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <cstring>
using namespace std;

long long arr[1505050];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;

	arr[1] = 1;
	for (int i = 0; i < 1505050; i++)
		arr[i + 2] = (arr[i + 1] + arr[i]) % 1000000;

	cout << arr[n % 1500000];

	return 0;
}
