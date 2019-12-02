/**
*	BOJ
*	No.10886	0 = not cute / 1 = cute
*	@author	peter9378
*	@date		2019.12.03
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

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int a = 0, b = 0;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp)
			a++;
		else
			b++;
	}

	if (a > b)
		cout << "Junhee is cute!";
	else
		cout << "Junhee is not cute!";
	return 0;
}
