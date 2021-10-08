/**
*	BOJ
*	No.2517 ´Þ¸®±â
*	@author	peter9378
*	@date		2021.10.08
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
int seg[500005];
vector<pair<int, int>> v;

int sum(int target)
{
    int result = 0;
    while (target > 0)
    {
        result += seg[target];
        target -= (target & -target);
    }
    return result;
}

void update(int target, int value)
{
    while (target <= N)
    {
        seg[target] += value;
        target += (target & -target);
    }
}

// main function
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        v.push_back({ temp, i + 1 });
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
        v[i].first = i + 1;
        swap(v[i].first, v[i].second);
    }

    sort(v.begin(), v.end());
    memset(seg, 0, sizeof(seg));

    for (int i = 0; i < N; i++)
    {
        int temp = v[i].second;
        cout << (i + 1) - sum(temp - 1) << "\n";
        update(temp, 1);
    }

    return 0;
}