/**
*	BOJ
*	No.2953	나는 요리사다
*	@author	peter9378
*	@date		2020.05.27
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

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int sum = a + b + c + d;
		arr[i] = sum;
	}

	int index = 0, answer = 0;
	for (int i = 0; i < 5; i++)
	{
		if (answer < arr[i])
		{
			answer = arr[i];
			index = i;
		}
	}

	cout << index + 1 << " " << answer;

	return 0;
}