/**
*	BOJ
*	No.7662	이중 우선순위 큐
*	@author	peter9378
*	@date		2020.05.23
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

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		multiset<int> s;
		for (int i = 0; i < N; i++)
		{
			char cmd;
			int target;

			cin >> cmd >> target;

			if (cmd == 'I')
				s.insert(target);
			else
			{
				if (!s.empty())
				{
					if (target == 1)
						s.erase(--s.end());
					else
						s.erase(s.begin());
				}
			}
		}

		if (s.empty())
			cout << "EMPTY\n";
		else
			cout << *(--s.end()) << " " << *s.begin() << "\n";
	}

	return 0;
}