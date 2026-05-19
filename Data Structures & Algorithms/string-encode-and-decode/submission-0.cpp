class Solution {
public:

    string encode(vector<string>& strs) {
        // Use a simple shift cipher
        // Shift each char over 7 places
        // Use the \0 to separate each string for decoding
        string cipher;
        for (string s : strs)
        {
            string shiftWord;
            // Append length first
            shiftWord += to_string(s.size());
            shiftWord += '#';
            for (char c : s)
            {
                if (islower(c))
                    shiftWord += char('a' + ((c - 'a' + 7) % 26));
                else if (isupper(c))
                    shiftWord += char('A' + ((c - 'A' + 7) % 26));
                else    
                    shiftWord += c;

            }
            cipher.append(shiftWord);
        }

        return cipher;

    }

    vector<string> decode(string s) {
        vector<string> answer;
        int i = 0;
        while (i < s.size())
        {
            // Parse length
            int length = 0;
            while (isdigit(s[i])) {
                length = length * 10 + (s[i] - '0');
                i++;
            }
            // Skip #
            i++;
            // Decode
            string word;

            for (int j = 0; j < length; j++) {
                char c = s[i++];

                if (islower(c))
                    word += char('a' + (c - 'a' - 7 + 26) % 26);
                else if (isupper(c))
                    word += char('A' + (c - 'A' - 7 + 26) % 26);
                else
                    word += c;
            }
            answer.push_back(word);
        }
        return answer;
    }
};
