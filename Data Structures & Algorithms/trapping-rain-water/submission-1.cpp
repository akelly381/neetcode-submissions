class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int left = 0;
        int right = len - 1;
        vector<int> preMax(len);
        vector<int> postMax(len);
        // Calculate prefix and postfix maximums
        preMax[0] = height[0];
        for (int i = 1; i < len; i++)
        {
            preMax[i] = max(preMax[i - 1], height[i]);
        }
        postMax[len - 1] = height[len - 1];
        for (int j = len - 2; j>= 0; j--)
        {
            postMax[j] = max(postMax[j + 1], height[j]);
        }
        int totalWater = 0;
        for (int l = 0; l < len; l++)
        {
            totalWater += min(preMax[l], postMax[l]) - height[l];
        }

        return totalWater;
        
    }
};
