class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = -1;
        int i = 0;
        int j = height.size() - 1;
        while(i < j)
        {
            answer = max(answer, min(height[i], height[j]) * (j - i));
            if(height[j] >= height[i]) 
                i++;
            else
                j--;
        }
        
        return answer;
    }
};
