/**
*	BOJ
*	No.11404 플로이드
*	@author	peter9378
*	@date		2020.01.16
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

int arr[101][101];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m;
    cin >> n >> m;
 
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
            arr[i][j] = (i == j) ? 0 : 987654321;
    }
 
    for (int i = 0; i < m; i++) 
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a-1][b-1] = min(arr[a-1][b-1], c);
    }
 
    for (int a = 0; a < n; a++) 
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++)
                arr[i][j] = (arr[i][j] < (arr[i][a] + arr[a][j])) ? arr[i][j] : arr[i][a] + arr[a][j];
        }
    }
 
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (arr[i][j] == 987654321)
                cout << "0 ";
            else
                cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

	return 0;
}
