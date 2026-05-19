class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int numLen = nums.size();
        vector<int> result(numLen * 2);

        for (int i = 0; i < numLen; i++)
        {
            result[i] = nums[i];
            result[i + numLen] = nums[i];
        }

        return result;
    }
};