class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size();
        // Sort the array
        std::sort(nums.begin(), nums.end());

        // Iterate through array
        for (int i = 0; i < len - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int val = nums[i] * -1;

            // Use two pointer approach for all elements to the right of val
            int *l = &nums[i + 1];
            int *r = &nums[len - 1];
            while (l < r) 
            {
                if (*l + *r == val) {
                    vector<int> triple = {nums[i], *l, *r};
                    result.push_back(triple);
                     ++l;
                    --r;
                    while (l < r && *l == *(l - 1)) ++l;
                    while (l < r && *r == *(r + 1)) --r;
                }

                else if (*l + *r < val)
                    ++l;
                else if (*l + *r > val)
                    --r;
            }
        }
        return result;
    }
};
