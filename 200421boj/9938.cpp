/**
*	BOJ
*	No.9938	¹æ Ã»¼Ò
*	@author	peter9378
*	@date		2020.04.21
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

int arr[300003];
bool visit[300003];

int find(int a)
{
	if (a == arr[a])
		return a;
	return arr[a] = find(arr[a]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	arr[a] = b;
	cout << "LADICA\n";
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, L;
	cin >> N >> L;

	for (int i = 1; i <= L; i++)
		arr[i] = i;

	for (int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;

		if (!visit[a])
		{
			visit[a] = true;
			merge(a, b);
		}
		else if (!visit[b])
		{
			visit[b] = true;
			merge(b, a);
		}
		else if (!visit[find(arr[a])])
		{
			visit[find(arr[a])] = true;
			merge(a, b);
		}
		else if (!visit[find(arr[b])])
		{
			visit[find(arr[b])] = true;
			merge(b, a);
		}
		else
			cout << "SMECE\n";
	}

	return 0;
}