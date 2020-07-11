/**
*	BOJ
*	No.17626	Four Squares
*	@author	peter9378
*	@date		2020.07.11
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
#include <unordered_map>
#include <cstring>
#include <iterator>
#include <numeric>
using namespace std;

int arr[50005];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
		for (int j = 1; j*j <= i; j++)
			arr[i] = min(arr[i], arr[i - j * j] + 1);
	}

	cout << arr[n];

	return 0;
}