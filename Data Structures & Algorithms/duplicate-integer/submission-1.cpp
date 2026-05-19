class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map <int, int> numCounts; // < val, cnt>
        // Count elements
        for (int n : nums)
        {
            numCounts[n]++;
        }

        // Check if any value > 1
        for (const auto& pair : numCounts)
        {
            if (pair.second > 1)
                return true;
        }

        return false;
    }
};