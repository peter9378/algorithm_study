/**
*	BOJ
*	No.1120 문자열
*	@author	peter9378
*	@date		2020.01.09
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

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    string a, b;
    cin >> a >> b;

    int answer = 987654321;
    for (int i = 0; i <= b.length() - a.length(); i++)
    {
        int temp = 0;

        for (int j = 0; j < a.length(); j++)
        {
            if(a[j] != b[i + j])
                temp++;
        }
        answer = min(answer, temp);
    }

    cout << answer;

	return 0;
}
