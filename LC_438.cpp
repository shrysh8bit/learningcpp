class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};
        
        vector<int> v1(26,0), v2(26, 0);
        vector<int> ans;
        
        for ( int pr : p){
            v1[pr - 'a'] += 1;
        }
        
        for (int i = 0; i < p.size(); i++){
            v2[s[i] - 'a'] += 1;
        }
        
        if(v1 == v2) ans.push_back(0);
        
        int size_p = p.size();
        
        
        for ( int i = 0; i < s.size() - size_p; i++ ){
         
            v2[s[i] - 'a'] -= 1;
            v2[s[i + size_p] - 'a'] += 1;
            
            if(v1 == v2) ans.push_back(i + 1);
        
        }
        
        return ans;
        
    }
};