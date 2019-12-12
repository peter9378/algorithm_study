/**
*	BOJ
*	No.1111	IQ Test
*	@author	peter9378
*	@date		2019.12.13
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

	int N;
	cin >> N;

	int a = 0, b = 0;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	if (N == 1)
		cout << "A";
	else if (N == 2)
	{
		if (v[0] == v[1])
			cout << v[0];
		else
			cout << "A";
	}
	else
	{
		bool flag = true;
		int current = v[0];
		int next = v[1];
		int nextnext = v[2];

		if (next == current)
		{
			a = 0;
			b = next;
		}
		else
		{
			a = (nextnext - next) / (next - current);
			b = next - (current*a);
		}

		for (int i = 1; i < N - 1; i++)
		{
			int temp = v[i] * a + b;
			int temptemp = v[i + 1];

			if (temp != temptemp)
				flag = false;
		}

		if (flag)
			cout << v[N - 1] * a + b;
		else
			cout << "B";
	}

	return 0;
}
