class Solution {
public:
    int firstUniqChar(string s) {
        int match;
        for ( int i = 0; i < s.size() ; i++){
            match = 0;
            for ( int j = 0; j < s.size(); j++){
                if (i != j){
                    if (s[i] == s[j]){
                        match = 1;
                        break;
                    }
                }
            }
            if ( match == 0){
                return i;
            }
        }
        return -1;
    }
};