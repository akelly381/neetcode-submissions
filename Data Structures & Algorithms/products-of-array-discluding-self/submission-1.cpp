class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeroCnt = 0;
        // Create product of entire array (ignore 0s)
        for (int n : nums)
        {
            if (n != 0) product *= n;
            else zeroCnt++;
        }

        vector<int> prods;
        for (int n : nums)
        {
            if (zeroCnt > 1)
            {
                prods.push_back(0);
            }
            else if (zeroCnt == 1)
            {
                if (n != 0) 
                    prods.push_back(0);
                else 
                    prods.push_back(product);
            }
            else 
                prods.push_back(product / n);
        }

        return prods;

    }
};
