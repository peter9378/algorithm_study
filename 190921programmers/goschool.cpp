#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007

long long arr[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    for(int i=0;i<puddles.size();i++)
        arr[puddles[i][1]-1][puddles[i][0]-1] = -1;
    
    for(int i=0;i<m;i++)
    {
        if(arr[0][i] == -1)
        {
            for(int j=i;j<m;j++)
                arr[0][j] = 0;
            break;
        }
        arr[0][i] = 1;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i][0] == -1)
        {
            for(int j=i;j<n;j++)
                arr[j][0] = 0;
            break;
        }
        arr[i][0] = 1;
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[i][j] == -1)
                arr[i][j] = 0;
            else
                arr[i][j] = (arr[i-1][j]+arr[i][j-1])%MOD;
        }
    }
    
    
    return arr[n-1][m-1]%MOD;
}