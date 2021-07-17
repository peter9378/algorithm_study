/**
*	BOJ
*	No.1145	적어도 대부분의 배수
*	@author	peter9378
*	@date		2021.07.17
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

int arr[5];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 5; i++)
		cin >> arr[i];

	int result = 1;
	while (1)
	{
		int temp = 0;
		for (int i = 0; i < 5; i++)
		{
			if (result >= arr[i] && result % arr[i] == 0)
				temp++;
		}

		if (temp >= 3)
		{
			cout << result << "\n";
			break;
		}

		result++;
	}

	return 0;
}
