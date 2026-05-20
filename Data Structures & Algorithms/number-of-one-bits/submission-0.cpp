class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t mask = 1; 
        int count = 0;
        int num = n;
        // Iterate through number
        for (int i = 0; i < 32; i++)
        {
            if (n & mask) count++;
            mask <<= 1;
        }

        return count;
    }
};
