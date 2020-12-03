/**
*	BOJ
*	No.1150	¹é¾÷
*	@author	peter9378
*	@date		2020.12.03
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

typedef struct {
	int left, right, value;
} input;

input arr[100002];
int dp[100002];

typedef struct {
	int left, right, length;
} element;

struct compare {
	bool operator() (element a, element b)
	{
		return a.length > b.length;
	}
};

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].value;
		arr[i].left = i - 1;
		arr[i].right = i + 1;
	}

	priority_queue<element, vector<element>, compare> pq;
	for (int i = 1; i < n; i++)
	{
		element temp;
		temp.left = i;
		temp.right = i + 1;
		temp.length = arr[i + 1].value - arr[i].value;
		pq.push(temp);
		dp[i] = temp.length;
	}

	int answer = 0;
	while (k--)
	{
		element temp = pq.top();
		pq.pop();

		int left = temp.left;
		int right = temp.right;
		int length = temp.length;

		if (left < 1 || right > n || right != arr[left].right || left != arr[right].left)
		{
			k++;
			continue;
		}

		answer += length;
		int nleft = arr[left].left;
		int nright = arr[right].right;

		temp.left = nleft;
		temp.right = nright;
		dp[nleft] = dp[nleft] + dp[right] - length;
		temp.length = dp[nleft];
		pq.push(temp);

		arr[nleft].right = nright;
		arr[nright].left = nleft;
	}

	cout << answer;

	return 0;
}
