/**
*	BOJ
*	No.1075	³ª´©±â
*	@author	peter9378
*	@date		2020.04.22
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

	int N, F;
	cin >> N >> F;

	N = (N / 100) * 100;

	int i;
	for (i = 0; i < 100; i++)
	{
		int temp = N;
		if ((temp += i) % F == 0)
			break;
	}

	if (i < 10)
		cout << 0;
	cout << i;


	return 0;
}