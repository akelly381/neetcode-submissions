class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> result(nums.size());

       // Calculate prefix products
       int prefix = 1;
       for (int i = 0; i < nums.size(); i++)
       {
        result[i] = prefix;
        prefix *= nums[i];
       }

       // Calculate postfix products
       int postfix = 1;
       for (int i = nums.size() - 1; i >= 0; i--)
       {
        result[i] *= postfix;
        postfix *= nums[i];
       }

       return result;
    }
};
