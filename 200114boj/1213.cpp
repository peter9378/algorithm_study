/**
*	BOJ
*	No.1213 팰린드롬 만들기
*	@author	peter9378
*	@date		2020.01.14
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

int arr[26];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
        arr[s[i] - 'A']++;
    
    int diff = 0, mid = -1;
 
    for (int i = 0; i < 26; i++) 
    {
        if (arr[i] > 0) 
        {
            if (arr[i] % 2 == 1)
            {
                mid = i;
                arr[i]--;
                diff++;
            }
        }
    }
 
    if (diff > 1)
        cout << "I'm Sorry Hansoo\n";
    else 
    {
        string answer = "";
        string temp = "";
        for (int i = 0; i < 26; i++) 
        {
            if (arr[i])
            {
                for (int j = 0; j < arr[i] / 2; j++)
                    answer += i + 'A';
            }
        }
        temp = answer;
        reverse(temp.begin(), temp.end());
        if (mid != -1)
            answer += mid + 'A';
        answer += temp;
        cout << answer << "\n";
    }

	return 0;
}
