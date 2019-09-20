#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 1;
	sort(routes.begin(), routes.end());

	int pvt = routes[0][1];
	for (int i = 1; i < routes.size(); i++)
	{
		if (pvt > routes[i - 1][1])
			pvt = routes[i - 1][1];
		if (routes[i][0] > pvt)
		{
			answer++;
			pvt = routes[i][1];
		}
	}
	return answer;
}