class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Remove all instances of val
        erase(nums, val);
        int afterSize = nums.size();
        return afterSize;

        
    }
};