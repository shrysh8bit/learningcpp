class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ptr = 0;

        for (char i : t){
            if (i == s[ptr]) ptr++;
        } 

        return ptr == s.size();
    }
};