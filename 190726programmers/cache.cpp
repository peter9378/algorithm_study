/**
*	Programmers
*	Ä³½Ã
*	@author	peter9378
*	@date		2019.07.26
*/
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

string lower(string target)
{
    for(int i=0;i<target.length();i++)
    {
        if(target[i]>96)
            target[i] -= 32;
    }
    return target;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	list<string> li;

	if (cacheSize)
	{
		for (int i = 0; i < cities.size(); i++)
		{
			string temp = lower(cities[i]);
			list<string>::iterator iter = find(li.begin(), li.end(), temp);
			if (iter != li.end())
			{
				answer++;
				li.erase(iter);
				li.push_back(temp);
			}
			else
			{
				if (li.size() == cacheSize)
					li.erase(li.begin());
				li.push_back(temp);
				answer += 5;
			}
		}
	}
	else
		answer = 5 * cities.size();
	return answer;
}