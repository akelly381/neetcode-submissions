
class Solution {
public:
    bool isPalindrome(string s) {
        int n = (int)s.length();

        const char* left  = s.c_str();
        const char* right = s.c_str() + n - 1;

        while (left < right)
        {      
            while (left < right && !isalnum(*left)) ++left;
            while (left < right && !isalnum(*right)) --right;
            if (tolower(*left) != tolower(*right))
                return false;
            // Advance pointers
            ++left;
            --right;
        }
        
        return true;
        
    }
};
