/**
*	BOJ
*	No.3986 ¿¿ ¿¿
*	@author	peter9378
*	@date		2021.01.17
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

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int N;
    cin >> N;

    int answer = 0;
    for(int i=0;i<N;i++)
    {
        string s;
        cin >> s;

        stack<char> stk;
        for(int j=0;j<s.length();j++)
        {
            if(!stk.empty() && stk.top() == s[j])
                stk.pop();
            else
                stk.push(s[j]);
        }

        if(stk.empty())
            answer++;
    }
    
    cout << answer;
	return 0;
}
