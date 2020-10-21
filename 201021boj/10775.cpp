/**
*	BOJ
*	No.10775	°øÇ×
*	@author	peter9378
*	@date		2020.10.21
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
#include <unordered_map>
#include <cstring>
#include <iterator>
#include <numeric>
#include <complex>
using namespace std;

int arr[100001];

int go(int target) 
{
	if (target == arr[target])
		return arr[target];
	return arr[target] = go(arr[target]);
}

void go_union(int a, int b) 
{
	int x = go(a);
	int y = go(b);

	arr[x] = y;

}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int G, P;
	cin >> G >> P;

	for (int i = 0; i <= G; i++)
		arr[i] = i;

	int answer = 0;
	for (int i = 0; i < P; i++)
	{
		int a;
		cin >> a;

		int parent = go(a);
		if (parent)
		{
			answer++;
			go_union(parent, parent - 1);
		}
		else
			break;
	}

	cout << answer;

	return 0;
}