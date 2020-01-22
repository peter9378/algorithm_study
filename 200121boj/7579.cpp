
/**
*	BOJ
*	No.7579	앱
*	@author	peter9378
*	@date		2020.01.21
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

int arr[101];
int cost[101];
int dp[101][10001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    for(int i = 0;i < N;i++)
        cin >> arr[i];
    
    for(int i = 0;i < N;i++)
        cin >> cost[i];

    int answer = 987654321;
    dp[0][cost[0]] = arr[0];
    for(int i = 1;i < N;i++)
    {
        for(int j = 0;j < 10000;j++)
        {
            if(j >= cost[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + arr[i]);

            dp[i][j] = max(dp[i][j], dp[i - 1][j]);

            if(dp[i][j] >= M)
                answer = min(answer, j);
        }
    }

    cout << answer;
    
	return 0;
}
