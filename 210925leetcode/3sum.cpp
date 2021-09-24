class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        
        sort(nums.begin(), nums.end());
        for(unsigned int i=0;i<nums.size();i++)
        {
            if (i && nums[i] == nums[i-1])
                continue;
            
            int left = i + 1;
            int right = nums.size()-1;
            
            while (left < right)
            {
                int temp = nums[i] + nums[left] + nums[right];
                if (temp > 0)
                    right--;
                else if (temp < 0)
                    left++;
                else
                {
                    answer.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left+1])
                        left++;
                    while (left < right && nums[right] == nums[right-1])
                        right--;
                    left++;
                    right--;
                }
            }
        }
        return answer;
    }
};
