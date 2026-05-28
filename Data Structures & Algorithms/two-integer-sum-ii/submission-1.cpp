class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;

        // [2, 4, 5, 6, 8, 10] target = 11
        int left = 0, right = numbers.size() - 1;
        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
            {
                return {left + 1, right + 1};
            }
            else if (sum < target) left++;
            else right--;
        }

        return result;
    }
};
