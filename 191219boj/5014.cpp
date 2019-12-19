/**
*	BOJ
*	No.5014	스타트링크
*	@author	peter9378
*	@date		2019.12.19
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

int arr[1000001];
bool check[1000001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	queue<int> q;
	q.push(S);
	arr[S] = 0;
	check[S] = true;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		int next = current + U;
		if (next <= F && !check[next])
		{
			check[next] = true;
			arr[next] = arr[current] + 1;
			q.push(next);
		}

		next = current - D;
		if (1 <= next && !check[next])
		{
			check[next] = true;
			arr[next] = arr[current] + 1;
			q.push(next);
		}
	}

	if (check[G])
		cout << arr[G];
	else
		cout << "use the stairs";

	return 0;
}
