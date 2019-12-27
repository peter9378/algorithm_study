/**
*	BOJ
*	No.11286	Àý´ñ°ª Èü
*	@author	peter9378
*	@date		2019.12.28
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

struct s {
	int num;
};

struct compare {
	bool operator()(s a, s b)
	{
		if (abs(a.num) == abs(b.num))
			return a.num > b.num;
		return abs(a.num) > abs(b.num);
	}
};

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	priority_queue<s, vector<s>, compare> q;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		if (temp)
		{
			s stemp;
			stemp.num = temp;
			q.push(stemp);
		}
		else
		{
			if (q.empty())
				cout << "0\n";
			else
			{
				cout << q.top().num << "\n";
				q.pop();
			}
		}
	}

	return 0;
}
