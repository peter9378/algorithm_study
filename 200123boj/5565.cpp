/**
*	BOJ
*	No.5565	¿µ¼öÁõ
*	@author	peter9378
*	@date		2020.01.23
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

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int total;
	cin >> total;

	for (int i = 0; i < 9; i++)
	{
		int temp;
		cin >> temp;
		total -= temp;
	}

	cout << total;

	return 0;
}
