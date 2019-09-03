/**
*	BOJ
*	No.1938	통나무 옮기기
*	@author	peter9378
*	@date		2019.09.04
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N;
string arr[51];
set<vector<pair<int, int>>> s;
vector<pair<int, int>> tree;
vector<pair<int, int>> target;

struct tong {
	int x, y;
	int count;
};

bool compare(const tong &a, const tong &b)
{
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}


bool border_safe(int target)
{
	return target >= 0 && target < N;
}

bool end(vector<pair<int, int>> v)
{
	for (int i = 0; i < 3; i++)
	{
		if (target[i].first != v[i].first || target[i].second != v[i].second)
			return false;
	}
	return true;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 'B')
			{
				tree.push_back(make_pair(i, j));
				arr[i][j] = '0';
			}
			else if (arr[i][j] == 'E')
			{
				target.push_back(make_pair(i, j));
				arr[i][j] = '0';
			}
		}
	}

	sort(tree.begin(), tree.end());
	sort(target.begin(), target.end());

	queue<vector<tong>> q;
	s.insert(tree);
	vector<tong> t;
	for (int i = 0; i < 3; i++)
		t.push_back(tong({ tree[i].first, tree[i].second, 1 }));
	q.push(t);

	int answer = 0;
	while (!q.empty())
	{
		vector<pair<int, int>> temp;
		int ct = q.front()[0].count;
		for (int i = 0; i < 3; i++)
			temp.push_back(make_pair(q.front()[i].x, q.front()[i].y));
		q.pop();

		// U
		int a, b, c;
		vector<pair<int, int>> t;
		a = temp[0].first - 1;
		b = temp[1].first - 1;
		c = temp[2].first - 1;

		if (border_safe(a) && border_safe(b) && border_safe(c))
		{
			if (arr[a][temp[0].second] != '1' && arr[b][temp[1].second] != '1' && arr[c][temp[2].second] != '1')
			{
				t.push_back(make_pair(a, temp[0].second));
				t.push_back(make_pair(b, temp[1].second));
				t.push_back(make_pair(c, temp[2].second));
				sort(t.begin(), t.end());
				if (end(t))
				{
					answer = ct;
					break;
				}
			}
		}
		if (!t.empty() && s.find(t) == s.end())
		{
			s.insert(t);
			vector<tong> tt;
			for (int i = 0; i < 3; i++)
				tt.push_back(tong({ t[i].first, t[i].second,  ct + 1 }));
			q.push(tt);
		}

		// D
		t.clear();
		a = temp[0].first + 1;
		b = temp[1].first + 1;
		c = temp[2].first + 1;

		if (border_safe(a) && border_safe(b) && border_safe(c))
		{
			if (arr[a][temp[0].second] != '1' && arr[b][temp[1].second] != '1' && arr[c][temp[2].second] != '1')
			{
				t.push_back(make_pair(a, temp[0].second));
				t.push_back(make_pair(b, temp[1].second));
				t.push_back(make_pair(c, temp[2].second));
				sort(t.begin(), t.end());
				if (end(t))
				{
					answer = ct;
					break;
				}
			}
		}
		if (!t.empty() && s.find(t) == s.end())
		{
			s.insert(t);
			vector<tong> tt;
			for (int i = 0; i < 3; i++)
				tt.push_back(tong({ t[i].first, t[i].second,  ct + 1 }));
			q.push(tt);
		}

		// L
		t.clear();
		a = temp[0].second - 1;
		b = temp[1].second - 1;
		c = temp[2].second - 1;

		if (border_safe(a) && border_safe(b) && border_safe(c))
		{
			if (arr[temp[0].first][a] != '1' && arr[temp[1].first][b] != '1' && arr[temp[2].first][c] != '1')
			{
				t.push_back(make_pair(temp[0].first, a));
				t.push_back(make_pair(temp[1].first, b));
				t.push_back(make_pair(temp[2].first, c));
				sort(t.begin(), t.end());
				if (end(t))
				{
					answer = ct;
					break;
				}
			}
		}
		if (!t.empty() && s.find(t) == s.end())
		{
			s.insert(t);
			vector<tong> tt;
			for (int i = 0; i < 3; i++)
				tt.push_back(tong({ t[i].first, t[i].second,  ct + 1 }));
			q.push(tt);
		}

		// R
		t.clear();
		a = temp[0].second + 1;
		b = temp[1].second + 1;
		c = temp[2].second + 1;

		if (border_safe(a) && border_safe(b) && border_safe(c))
		{
			if (arr[temp[0].first][a] != '1' && arr[temp[1].first][b] != '1' && arr[temp[2].first][c] != '1')
			{
				t.push_back(make_pair(temp[0].first, a));
				t.push_back(make_pair(temp[1].first, b));
				t.push_back(make_pair(temp[2].first, c));
				sort(t.begin(), t.end());
				if (end(t))
				{
					answer = ct;
					break;
				}
			}
		}
		if (!t.empty() && s.find(t) == s.end())
		{
			s.insert(t);
			vector<tong> tt;
			for (int i = 0; i < 3; i++)
				tt.push_back(tong({ t[i].first, t[i].second,  ct + 1 }));
			q.push(tt);
		}

		// T
		t.clear();
		if (temp[0].first == temp[1].first)	// ---
		{
			a = temp[0].first - 1;
			b = temp[1].first - 1;
			c = temp[2].first - 1;

			if (border_safe(a) && border_safe(b) && border_safe(c))
			{
				if (arr[a][temp[0].second] != '1' && arr[b][temp[1].second] != '1' && arr[c][temp[2].second] != '1')
				{
					a = temp[0].first + 1;
					b = temp[1].first + 1;
					c = temp[2].first + 1;

					if (border_safe(a) && border_safe(b) && border_safe(c))
					{
						if (arr[a][temp[0].second] != '1' && arr[b][temp[1].second] != '1' && arr[c][temp[2].second] != '1')
						{
							t.push_back(make_pair(temp[0].first - 1, temp[0].second + 1));
							t.push_back(make_pair(temp[1].first, temp[1].second));
							t.push_back(make_pair(temp[2].first + 1, temp[2].second - 1));
							sort(t.begin(), t.end());
							if (end(t))
							{
								answer = ct;
								break;
							}
						}
					}
				}
			}
		}
		else	// |
		{
			a = temp[0].second - 1;
			b = temp[1].second - 1;
			c = temp[2].second - 1;

			if (border_safe(a) && border_safe(b) && border_safe(c))
			{
				if (arr[temp[0].first][a] != '1' && arr[temp[1].first][b] != '1' && arr[temp[2].first][c] != '1')
				{
					a = temp[0].second + 1;
					b = temp[1].second + 1;
					c = temp[2].second + 1;

					if (border_safe(a) && border_safe(b) && border_safe(c))
					{
						if (arr[temp[0].first][a] != '1' && arr[temp[1].first][b] != '1' && arr[temp[2].first][c] != '1')
						{
							t.push_back(make_pair(temp[0].first + 1, temp[0].second - 1));
							t.push_back(make_pair(temp[1].first, temp[1].second));
							t.push_back(make_pair(temp[2].first - 1, temp[2].second + 1));
							sort(t.begin(), t.end());
							if (end(t))
							{
								answer = ct;
								break;
							}
						}
					}
				}
			}
		}
		if (!t.empty() && s.find(t) == s.end())
		{
			s.insert(t);
			vector<tong> tt;
			for (int i = 0; i < 3; i++)
				tt.push_back(tong({ t[i].first, t[i].second,  ct + 1 }));
			q.push(tt);
		}
	}

	if (answer)
		cout << answer;
	else
		cout << 0;

	return 0;
}