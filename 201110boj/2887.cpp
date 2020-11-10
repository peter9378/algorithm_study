/**
*	BOJ
*	No.2887	행성 터널
*	@author	peter9378
*	@date		2020.11.10
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

int N;
int parent[100000];

struct planet {
	int x, y, z, cost;
};

struct edge {
	int weight, from, to;
};

planet arr[100000];
vector<edge> v;

bool comparex(const planet& p1, const planet& p2)
{
	return p1.x > p2.x;
}

bool comparey(const planet& p1, const planet& p2)
{
	return p1.y > p2.y;
}

bool comparez(const planet& p1, const planet& p2)
{
	return p1.z > p2.z;
}


bool operator<(const edge& e1, const edge& e2)
{
	return e1.weight > e2.weight;
}

int find(int target)
{
	if (target == parent[target])
		return target;
	return parent[target] = find(parent[target]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	parent[x] = y;
	return;
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].x >> arr[i].y >> arr[i].z;
		arr[i].cost = i;
		parent[i] = i;
	}

	sort(arr, arr + N, comparex);
	for (int i = 0; i < N - 1; i++)
		v.push_back(edge({ abs(arr[i].x - arr[i + 1].x), arr[i].cost, arr[i + 1].cost }));

	sort(arr, arr + N, comparey);
	for (int i = 0; i < N - 1; i++)
		v.push_back(edge({ abs(arr[i].y - arr[i + 1].y), arr[i].cost, arr[i + 1].cost }));

	sort(arr, arr + N, comparez);
	for (int i = 0; i < N - 1; i++)
		v.push_back(edge({ abs(arr[i].z - arr[i + 1].z), arr[i].cost, arr[i + 1].cost }));

	sort(v.begin(), v.end());

	int answer = 0;
	int cnt = 0;
	for (int i = v.size() - 1; cnt != N - 1; --i)
	{
		if (find(v[i].from) != find(v[i].to))
		{
			cnt++;
			answer += v[i].weight;
			merge(v[i].from, v[i].to);
		}

		if (cnt == N - 1)
			break;
	}

	cout << answer;

	return 0;
}