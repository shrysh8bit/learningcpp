class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> seen (150,0);
        int count = 0, odd = 0;
        for (int i = 0; i < s.size(); i++){
            seen[(int)s[i]]++;
        }

        for (int i : seen){
            if(i > 1){
                count += 2*(i/2);
            }

            if (i %2 ) odd = 1;
        }

        return count + odd;
    }
};
