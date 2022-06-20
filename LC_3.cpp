class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        
        int l = 0, r = 0, size_max = 0, size_curr = 0;
        
        while(r < s.size()){
            if(set.find(s[r]) != set.end()){
                set.erase(s[l]);
                l++;
                size_curr--;
                continue;
            }else{
                set.insert(s[r]);
                size_curr++;
                size_max = max(size_max, size_curr);
                r++;
            }
        }
        
        return size_max;
        
    }
};