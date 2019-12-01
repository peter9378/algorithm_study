/**
*	BOJ
*	No.10867	중복 빼고 정렬하기
*	@author	peter9378
*	@date		2019.12.01
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

using namespace std;

bool arr[2002];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		arr[temp + 1000] = true;
	}

	for (int i = 0; i < 2002; i++)
	{
		if (arr[i])
			cout << i - 1000 << " ";
	}

	return 0;
}
