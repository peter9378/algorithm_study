/**
*	BOJ
*	No.13549	¿¿¿¿ 3
*	@author peter9378
*	@date		2020.12.30
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

#define MAX 100001

int N, K;
bool visit[MAX];

int bfs()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, N });
    visit[N] = true;

    while(!pq.empty())
    {
        int time = pq.top().first;
        int position = pq.top().second;
        pq.pop();

        if (position == K)
            return time;

        if (position * 2 < MAX && !visit[position * 2])
        {
            pq.push({ time, position * 2 });
            visit[position * 2] = true;
        }

        if (position + 1 < MAX && !visit[position + 1])
        {
            pq.push({ time + 1, position + 1 });
            visit[position + 1] = true;
        }

        if (position > 0 && !visit[position - 1])
        {
            pq.push({ time + 1, position - 1});
            visit[position - 1] = true;
        }
    }
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> N >> K;
    cout << bfs();

	return 0;
}
