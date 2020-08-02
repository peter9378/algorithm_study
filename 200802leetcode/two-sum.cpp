class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		vector<int> answer;
		for (int i = 0; i < nums.size(); i++) {
			if (m.find(target - nums[i]) == m.end()) {
				m[nums[i]] = i;
			}
			else {
				answer.push_back(m[target - nums[i]]);
				answer.push_back(i);
				break;
			}
		}
		return answer;
	}
};