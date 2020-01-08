/**
*	BOJ
*	No.1963	소수 경로
*	@author	peter9378
*	@date		2020.01.08
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

int arr[10001];
bool prime[10001];
bool check[10001];

void init()
{
	for(int i=0;i<10001;i++)
	{
		check[i] = false;
		arr[i] = 0;
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i=2;i<10001;i++)
	{
		if(!prime[i])
		{
			for(int j=i*i;j<10001;j+=i)
				prime[j] = true;
		}
	}

	int T;
	cin >> T;

	while(T--)
	{
		int a, b;
		cin >> a >> b;

		init();

		queue<int> q;
		check[a] = true;
		arr[a] = 0;
		q.push(a);

		while(!q.empty())
		{
			int current = q.front(); 
			q.pop();

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 10; j++)
                {
					if(i == 0 && j == 0)
						continue;

					string s = to_string(current);
					s[i] = (j + '0');
                    int next = stoi(s);

					if (!prime[next] && !check[next])
					{
						q.push(next);
						arr[next] = arr[current] + 1;
						check[next] = true;
					}
                }
            }
		}
        
		cout << arr[b] << "\n";        
	}

	return 0;
}
