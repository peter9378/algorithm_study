/**
*	BOJ
*	No.11405    책 구매하기
*	@author	peter9378
*	@date		2021.10.05
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

#define MAX 300
#define S MAX - 2
#define T MAX - 1

struct Edge {
    int vertex, cost, count, flow, revertex;
    Edge(int vertex, int cost, int count, int flow, int revertex)
        :vertex(vertex), cost(cost), count(count), flow(flow), revertex(revertex) {}
};

vector<Edge> arr[MAX];

void add_edge(int current, int target, int cost, int count)
{
    arr[current].emplace_back(target, cost, count, 0, arr[target].size());
    arr[target].emplace_back(current, -cost, 0, 0, arr[current].size() - 1);
}

// main function
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int j = 1; j <= N; j++)
    {
        int temp;
        cin >> temp;

        add_edge(j + M, T, 0, temp);
    }

    for (int i = 1; i <= M; i++)
    {
        int temp;
        cin >> temp;

        add_edge(S, i, 0, temp);
    }

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int temp;
            cin >> temp;

            add_edge(i, j + M, temp, 987654321);
        }
    }

    int answer = 0;
    while (1)
    {
        int temp_vertex[MAX], end_vertex[MAX], distance[MAX];
        bool check[MAX] = { 0 };

        queue<int> q;
        fill(temp_vertex, temp_vertex + MAX, -1);
        fill(end_vertex, end_vertex + MAX, -1);
        fill(distance, distance + MAX, 987654321);

        distance[S] = 0;
        check[S] = true;
        q.push(S);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            check[current] = false;

            for (int i = 0; i < arr[current].size(); i++)
            {
                int next = arr[current][i].vertex;
                int count = arr[current][i].count;
                int flow = arr[current][i].flow;
                int cost = arr[current][i].cost;

                if (count > flow && distance[next] > distance[current] + cost)
                {
                    distance[next] = distance[current] + cost;
                    temp_vertex[next] = current;
                    end_vertex[next] = i;

                    if (!check[next])
                    {
                        q.push(next);
                        check[next] = true;
                    }
                }
            }
        }
        if (temp_vertex[T] == -1)
            break;

        int flow = 987654321;

        for (int i = T; i != S; i = temp_vertex[i])
        {
            int pre = temp_vertex[i];
            int index = end_vertex[i];
            flow = min(flow, arr[pre][index].count - arr[pre][index].flow);
        }

        for (int i = T; i != S; i = temp_vertex[i])
        {
            int pre = temp_vertex[i];
            int index = end_vertex[i];

            answer += arr[pre][index].cost * flow;
            arr[pre][index].flow += flow;
            arr[i][arr[pre][index].revertex].flow -= flow;

        }
    }

    cout << answer;

    return 0;
}