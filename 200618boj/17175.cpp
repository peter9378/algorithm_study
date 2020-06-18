/**
*	BOJ
*	No.17175	피보나치는 지겨웡~
*	@author	peter9378
*	@date		2020.06.18
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
#include <iterator>
#include <numeric>
using namespace std;

#define MOD 1000000007

int arr[55];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	arr[0] = arr[1] = 1;
	for (int i = 2; i <= n; i++)
		arr[i] = (arr[i - 1] + arr[i - 2] + 1) % MOD;

	cout << arr[n];

	return 0;
}
