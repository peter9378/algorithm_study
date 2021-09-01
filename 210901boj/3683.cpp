/**
*	BOJ
*	No.3683 고양이와 개
*	@author	peter9378
*	@date		2021.09.01
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

int v;
int arr[501];
bool visited[501];
vector<vector<int>> vv;
pair<string, string> vote[501];

bool dfs(int target)
{
    if (visited[target])
        return false;

    visited[target] = true;
    for (auto next : vv[target])
    {
        if (!arr[next] || dfs(arr[next]))
        {
            arr[next] = target;
            return true;
        }
    }
    return false;
}

int go()
{
    memset(arr, 0, sizeof(arr));

    int result = 0;
    for (int i = 1; i <= v; i++)
    {
        memset(visited, false, sizeof(visited));
        if (dfs(i))
            result++;
    }

    return v - result;
}

// main function
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int c, d;
        cin >> c >> d >> v;

        vv.clear();
        vv.resize(v + 1);

        string x, y;
        for (int i = 1; i <= v; i++)
        {
            cin >> x >> y;
            vote[i] = { x, y };
        }

        for (int i = 1; i <= v; i++)
        {
            for (int j = i + 1; j <= v; j++)
            {
                if (vote[i].first == vote[j].second || vote[i].second == vote[j].first)
                {
                    if (vote[i].first[0] == 'C')
                        vv[i].push_back(j);
                    else
                        vv[j].push_back(i);
                }
            }
        }

        cout << go() << "\n";
    }

    return 0;
}