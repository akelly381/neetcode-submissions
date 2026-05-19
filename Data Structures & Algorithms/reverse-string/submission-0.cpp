class Solution {
public:
    void reverseString(vector<char>& s) {
        char *ptr1, *ptr2;
        int len = s.size();
        
        for (int i = 0; i < floor(len / 2); i++)
        {
            ptr1 = &s[i];
            ptr2 = &s[len - i - 1];
            char first = *ptr1;
            char last = *ptr2;
            s[i] = last;
            s[len - i - 1] = first;
        }
    }
};