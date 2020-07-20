/**
*	BOJ
*	No.1138	한 줄로 서기
*	@author	peter9378
*	@date		2020.07.20
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

int arr[11];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		for (int j = 0; j < N; j++)
		{
			if (!a && !arr[j])
			{
				arr[j] = i + 1;
				break;
			}
			else if (!arr[j])
				a--;
		}
	}

	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";

	return 0;
}