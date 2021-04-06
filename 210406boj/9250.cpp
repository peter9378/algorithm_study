/**
*	BOJ
*	No.9250	문자열 집합 판별
*	@author	peter9378
*	@date		2021.04.06
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

struct Node {
	map<char, Node*> c;
	int t;
	Node *fail;
	vector<int> output;

	Node() : t(-1) {}
	~Node() {
		for (auto &i : c)
			delete i.second;
		c.clear();
	}

	void insert(const char *key, int target)
	{
		if (*key == 0)
		{
			t = target;
			return;
		}

		if (!c[*key])
			c[*key] = new Node();
		c[*key]->insert(key + 1, target);
	}
};

void aho(Node *root)
{
	queue<Node*> q;
	root->fail = root;
	q.push(root);

	while (q.size())
	{
		Node *now = q.front();
		q.pop();

		for (auto &i : now->c)
		{
			Node *child = i.second;
			if (!child)
				continue;

			if (root == now)
				child->fail = root;
			else
			{
				Node *t = now->fail;
				while (t != root && !t->c[i.first])
					t = t->fail;
				if (t->c[i.first])
					t = t->c[i.first];
				child->fail = t;
			}

			child->output = child->fail->output;
			if (child->t != -1)
				child->output.push_back(child->t);
			q.push(child);
		}
	}
}

vector<pair<int, int>> aho_find(string &s, Node *root)
{
	vector<pair<int, int>> result;
	auto state = root;
	for (int i = 0; i < s.size(); i++)
	{
		while (state != root && !state->c[s[i]])
			state = state->fail;
		if (state->c[s[i]])
			state = state->c[s[i]];
		for (int j = 0; j < state->output.size(); j++)
			result.push_back({ i, state->output[j] });
	}
	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, Q;
	cin >> N;

	Node *root = new Node();
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		root->insert(s.c_str(), i);
	}

	aho(root);
	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		string s;
		cin >> s;
		auto v = aho_find(s, root);
		cout << (v.size() ? "YES\n" : "NO\n");
	}

	return 0;
}
