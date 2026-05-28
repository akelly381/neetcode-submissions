class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = 0, maxArea = INT_MIN;
        int left = 0, right = heights.size() - 1;
        while (left < right)
        {
            area = min(heights[left], heights[right]) * (right - left);
            maxArea = max(maxArea, area);
            if (heights[left] < heights[right]) left++;
            else right--;
        }

        return maxArea;
        
    }
};
