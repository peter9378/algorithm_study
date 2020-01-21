
/**
*	BOJ
*	No.9019 DSLR
*	@author	peter9378
*	@date		2020.01.22
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
#include <cstring>
using namespace std;

pair<int, int> arr[10001];
bool visit[10001];

void init()
{
    for(int i = 0; i < 10001; i++)
        visit[i] = false;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;

    for(int i = 0; i < N; i++)
    {
        init();
        queue<pair<int, string>> q;
        q.push({arr[i].first, ""});
        visit[arr[i].first] = true;

        while(!q.empty())
        {
            int current = q.front().first;
            string s = q.front().second;
            q.pop();

            if(current == arr[i].second)
            {
                cout << s << "\n";
                break;
            }
            else
            {
                int next = current * 2 % 10000;

                if(!visit[next])
                {
                    visit[next] = true;
                    q.push({next, s + "D"});
                }

                if(current == 0)
                    next = 9999;
                else
                    next = current - 1;
                
                if(!visit[next])
                {
                    visit[next] = true;
                    q.push({next, s + "S"});
                }

                if(current != 0)
                {
                    next = current % 1000 * 10 + current / 1000;
                    if(!visit[next])
                    {
                        visit[next] = true;
                        q.push({next, s + "L"});
                    }
                    next = (current / 10) + (current % 10) * 1000;
                    if(!visit[next])
                    {
                        visit[next] = true;
                        q.push({next, s + "R"});
                    }
                }
            }
        }
    }

	return 0;
}
