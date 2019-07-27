/**
*	Programmers
*	비밀지도
*	@author	peter9378
*	@date		2019.07.27
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string getBin(int target, int n)
{
    string result = "";
    while(target)
    {
        if(target%2)
            result += "1";
        else
            result += "0";
        target/=2;
    }
    while(n!=result.length())
        result += "0";
    reverse(result.begin(), result.end());
    return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0;i<n;i++)
    {
        string s = "";
        for(int j=0;j<n;j++)
        {
            if((getBin(arr1[i], n)[j]-48) | (getBin(arr2[i], n)[j] - 48))
                s += "#";
            else
                s += " ";
        }
        answer.push_back(s);    
    }
    return answer;
}