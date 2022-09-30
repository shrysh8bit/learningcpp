class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> source (256,0);
        vector<int> target (256,0);
        int src = 39, tgt = 39;
        int temp;
        
        for (int i = 0; i < s.size(); i++){
            if(source[(int)s[i]] == 0) {
                src++;
                source[(int)s[i]] = src;
                temp = src;        
            }else{
                temp = source[(int)s[i]];
            }
            s[i] = char(temp);
        }
        
        for (int i = 0; i < t.size(); i++){
            if(target[(int)t[i]] == 0) {
                tgt++;
                target[(int)t[i]] = tgt;
                temp = tgt;        
            }else{
                temp = target[(int)t[i]];
            }
            
            t[i] = char(temp) ;
        }
        
        // cout << s << " " << t << endl;
        
        for (int i = 0; i < s.size(); i++){
            if(s[i] != t[i]) return 0;
        }
        
        return 1;
    }
};