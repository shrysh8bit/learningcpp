class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = 0, h = 0;
        if (needle.size() == 0) return 0;
        
        while (h < haystack.size()){
            if (haystack[h] == needle[n]){
                n++;
                h++;
                if ( n == needle.size() ) return h - n;
            }else if (n > 0){
                h = h -n + 1;
                n = 0;
            }else{
                
                h++;
            }
            
        }
        
        return -1;
    }
};