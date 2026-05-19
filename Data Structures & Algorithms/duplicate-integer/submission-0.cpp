class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> numsTable;

        for (int i : nums)
        {
            if (numsTable.contains(i)) 
                return true;
            numsTable.insert(i);
        }

        return false;
    }
};