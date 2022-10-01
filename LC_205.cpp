class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> src (256,0);
        vector<int> tgt (256,0);
        int c_s = 33, c_t = 33;
        char temp;

        for (int i = 0; i < s.size(); i++){
            if(src[(int)s[i]] == 0){
                src[(int)s[i]] = c_s;
                s[i] = (char)c_s;
                c_s++;
            }else{
                s[i] = (char)src[(int)s[i]];
            }
        }

        for (int i = 0; i < t.size(); i++){
            if(tgt[(int)t[i]] == 0){
                tgt[(int)t[i]] = c_t;
                t[i] = (char)c_t;
                c_t++;
            }else{
                t[i] = (char)tgt[(int)t[i]];
            }
        }

        return s==t;
    }
};