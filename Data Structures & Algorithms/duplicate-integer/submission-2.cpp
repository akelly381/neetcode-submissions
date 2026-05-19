class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       set<int> numCounts; // < val, cnt>
        // Count elements
        for (int n : nums)
        {
            if (numCounts.count(n)) 
                return true;
            numCounts.insert(n);
        }

        return false;
    }
};