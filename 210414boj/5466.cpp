/**
*	BOJ
*	No.5466	ªÛ¿Œ
*	@author	peter9378
*	@date		2021.04.14
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

#define MAX 500005
#define INF 0x3f3f3f3f3f3f3f3f

int N, U, D, S;
long long answer = 0;
long long f[MAX], g[MAX];

class Fair {
public:
	int t, l, m;
	Fair() {}
	Fair(int t_, int l_, int m_) : t(t_), l(l_), m(m_) {}
	inline bool operator < (const Fair &oth) const {
		return make_pair(t, l) < make_pair(oth.t, oth.l);
	}
} a[MAX];

class PrefixFenwickTree {
public:
	long long tree[MAX];

	inline PrefixFenwickTree() {
		for (int i = 0; i < MAX; i++)
			tree[i] = -INF;
		return;
	}

	inline void update(int x, long long k) {
		for (++x; x < MAX; x += x & (-x))
			tree[x] = max(tree[x], k);
		return;
	}

	inline long long query(int x) {
		long long result = -INF;
		for (++x; x; x -= x & (-x))
			result = max(result, tree[x]);
		return result;
	}
}pft;

class SuffixFenwickTree {
public:
	long long tree[MAX];

	inline SuffixFenwickTree() {
		for (int i = 0; i < MAX; i++)
			tree[i] = -INF;
		return;
	}

	inline void update(int x, long long k) {
		for (++x; x; x -= x & (-x))
			tree[x] = max(tree[x], k);;
		return;
	}

	inline long long query(int x) {
		long long result = -INF;
		for (++x; x < MAX; x += x & (-x))
			result = max(result, tree[x]);
		return result;
	}
}sft;

inline void update(int p) {
	pft.update(a[p].l, f[p] + a[p].l * D);
	sft.update(a[p].l, f[p] - a[p].l * U);
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> U >> D >> S;
	for (int i = 0; i < N; i++)
		cin >> a[i].t >> a[i].l >> a[i].m;

	a[N++] = Fair(0, S, 0);
	sort(a, a + N);
	update(0);

	for (int i = 1, j; i < N; i = j)
	{
		for (j = i; j < N && a[j].t == a[i].t; ++j)
		{
			g[j] = max(pft.query(a[j].l) - a[j].l * D, sft.query(a[j].l) + a[j].l * U);
			f[j] = -INF;
		}

		long long mx = -INF, sum = 0;
		for (j = i; j < N && a[j].t == a[i].t; ++j)
		{
			mx = max(mx, g[j] + a[j].l * D - sum);
			sum += a[j].m;
			f[j] = max(f[j], mx - a[j].l * D + sum);
		}
		mx = -INF, sum = 0;

		for (--j; j >= i; --j)
		{
			mx = max(mx, g[j] - a[j].l * U - sum);
			sum += a[j].m;
			f[j] = max(f[j], mx + a[j].l * U + sum);
		}

		for (j = i; j < N && a[j].t == a[i].t; ++j)
			update(j);
	}

	for (int i = 0; i < N; i++)
		answer = max(answer, f[i] - (a[i].l < a[0].l ? (a[0].l - a[i].l) * D : (a[i].l - a[0].l) * U));
	cout << answer;
	return 0;
}
