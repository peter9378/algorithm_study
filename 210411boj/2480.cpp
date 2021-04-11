/**
*	BOJ
*	No.2480	주사위 세개
*	@author	peter9378
*	@date		2021.04.11
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
#include <complex>
using namespace std;

int arr[7];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 3; i++)
	{
		int temp;
		cin >> temp;
		arr[temp]++;
	}

	int answer = 0;
	int maxi = -1;
	for (int i = 1; i <= 6; i++)
	{
		if (arr[i] == 1)
			maxi = max(i, maxi);
		else if (arr[i] == 2)
		{
			answer = 1000 + i * 100;
			break;
		}
		else if (arr[i] == 3)
		{
			answer = 10000 + i * 1000;
			break;
		}
	}

	cout << (answer ? answer : maxi * 100);

	return 0;
}
