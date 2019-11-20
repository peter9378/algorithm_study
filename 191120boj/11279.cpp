/**
*	BOJ
*	No.11279	ÃÖ´ë Èü
*	@author	peter9378
*	@date		2019.11.20
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int> q;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		if (x)
			q.push(x);
		else
		{
			if (q.empty())
				cout << "0\n";
			else
			{
				int temp = q.top();
				cout << temp << "\n";
				q.pop();
			}
		}
	}


	return 0;
}
