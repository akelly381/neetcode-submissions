class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::unordered_map<int, int> leftProd;
        std::unordered_map<int, int> rightProd;

        int prod;
        prod = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            // Store product up to this point
            leftProd[i] = prod;
            // Compute next product
            prod *= nums[i];
        }

        prod = 1;
        for (int j = nums.size() - 1; j >= 0; j--)
        {
            rightProd[j] = prod;
            prod *= nums[j];
        }

        vector<int> result;
        for (int k = 0; k < nums.size(); k++)
        {
            result.push_back(leftProd[k] * rightProd[k]);
        }

        return result;
    }
};
