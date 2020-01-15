/**
*	BOJ
*	No.2251	물통
*	@author	peter9378
*	@date		2020.01.15
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

bool visit[202][202][202];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	queue<tuple<int, int, int>> q;
	set<int> answer;
	q.push({ 0, 0, C });
	while (!q.empty())
	{
		int a = get<0>(q.front());
		int b = get<1>(q.front());
		int c = get<2>(q.front());
		q.pop();

		if (visit[a][b][c])
			continue;

		visit[a][b][c] = true;

		if (a == 0)
			answer.insert(c);

		if (a + b > B)
			q.push({ a + b - B, B, c });
		else
			q.push({ 0, a + b, c });

		if (a + c > C)
			q.push({ a + c - C, b, C });
		else
			q.push({ 0, b, a + c });

		if (a + b > A)
			q.push({ A, a + b - A, c });
		else
			q.push({ a + b, 0, c });

		if (b + c > C)
			q.push({ a, b + c - C, C });
		else
			q.push({ a, 0, b + c });

		if (b + c > B)
			q.push({ a, B, b + c - B });
		else
			q.push({ a, b + c, 0 });

		if (a + c > A)
			q.push({ A, b, a + c - A });
		else
			q.push({ a + c, b, 0 });
	}

	for (auto iter = answer.begin(); iter != answer.end(); iter++)
		cout << *iter << " ";

	return 0;
}
