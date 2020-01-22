
/**
*	BOJ
*	No.18258	큐 2
*	@author	peter9378
*	@date		2020.01.20
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

    int N;
    cin >> N;

    queue<int> q;
    for(int i=0;i<N;i++)
    {
        string s;
        cin >> s;

        if(s == "push")
        {
            int t;
            cin >> t;
            q.push(t);
        }
        else
        {
            if(s == "pop")
            {
                if(q.empty())
                    cout << "-1\n";
                else
                {
                    cout << q.front() << "\n";
                    q.pop();
                }
            }
            else if(s == "size")
                cout << q.size() << "\n";
            else if(s == "empty")
                cout << q.empty() << "\n";
            else if(s == "front")
            {
                if(q.empty())
                    cout << "-1\n";
                else
                    cout << q.front() << "\n";
            }
            else if(s == "back")
            {
                if(q.empty())
                    cout << "-1\n";
                else
                    cout << q.back() << "\n";
            }
        }
    }
    
	return 0;
}
