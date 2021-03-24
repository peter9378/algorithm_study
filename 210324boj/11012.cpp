/**
*	BOJ
*	No.11012	Egg
*	@author	peter9378
*	@date		2021.03.24
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

#define MAX 100005

struct node {
	long long val;
	node* left, *right;

	node(node* left = NULL, node* right = NULL) :
		left(left), right(right), val(0) {
	}

	node* insert(int left_value, int right_value, int target, long long value)
	{
		if (left_value <= target && target <= right_value)
		{
			if (left_value == right_value)
			{
				node* leaf = new node();
				leaf->val = this->val + value;
				return leaf;
			}

			int m = (left_value + right_value) >> 1;
			node* current_left = this->left->insert(left_value, m, target, value);
			node* current_right = this->right->insert(m + 1, right_value, target, value);
			node* leaf = new node(current_left, current_right);
			leaf->val = current_left->val + current_right->val;
			return leaf;
		}

		return this;
	}
};

long long query(node* target, int start, int endd, int left, int right)
{
	if (endd < left || right < start)
		return 0;

	if (left <= start && endd <= right)
		return target->val;

	int mid = (start + endd) >> 1;
	return query(target->left, start, mid, left, right) + query(target->right, mid + 1, endd, left, right);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int n, m;
		cin >> n >> m;

		vector<int> xpos[MAX];
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> y >> x;
			x++, y++;
			xpos[x].push_back(y);
		}

		vector<node*> v(MAX + 2);
		v[0] = new node();
		v[0]->left = v[0]->right = v[0];
		v[0]->val = 0;

		for (int y = 1; y < MAX; y++)
		{
			v[y] = v[y - 1];
			for (auto& x : xpos[y])
				v[y] = v[y]->insert(1, MAX, x, 1);
		}

		long long answer = 0;
		while (m--)
		{
			int l, r, b, u;
			cin >> l >> r >> b >> u;
			l++, r++, b++, u++;
			answer += query(v[u], 1, MAX, l, r);
			answer -= query(v[b - 1], 1, MAX, l, r);
		}
		cout << answer << "\n";
	}

	return 0;
}
