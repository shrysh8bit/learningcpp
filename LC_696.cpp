class Solution {
public:
    int countBinarySubstrings(string s) {
        int j,k;
        int count = 0;

        for (int i  = 0; i < s.size() -1 ; i++){
            if ((s[i] == '0' && s[i+1] == '1') || (s[i] == '1' && s[i+1] == '0')){
                count++;
                
                j = i;
                k = i + 1;

                while (j - 1 >= 0 && k + 1 < s.size()){

                    if (s[j-1] == s[j] && s[k] == s[k + 1] ){
                        j--;
                        k++;
                        count++;

                    }else{
                        break;
                    }
                }
            }
        }

        return count;
    }
};