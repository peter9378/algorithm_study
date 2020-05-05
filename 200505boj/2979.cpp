/**
*	BOJ
*	No.2979	트럭 주차
*	@author	peter9378
*	@date		2020.05.05
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

int arr[101];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	for (int i = 0; i < 3; i++)
	{
		int start, end;
		cin >> start >> end;

		for (int j = start; j < end; j++)
			arr[j]++;
	}

	int answer = 0;
	for (int i = 1; i < 101; i++)
	{
		if (arr[i] == 1)
			answer += arr[i] * a;
		else if (arr[i] == 2)
			answer += arr[i] * b;
		else
			answer += arr[i] * c;
	}

	cout << answer;

	return 0;
}