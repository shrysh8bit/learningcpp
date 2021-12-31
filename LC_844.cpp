class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> v1, v2;
        
        for (char pr : s){
            if (pr == '#' && v1.size() > 0){
                v1.pop_back();
           }
            
            if(pr != '#'){
                v1.push_back(pr);
            }
        }
        
        for (char pr : t){
            if (pr == '#' && v2.size() > 0) {v2.pop_back();}
            if (pr != '#'){
                v2.push_back(pr);
            }
        }
    if (v1 == v2) return true;
        
        return false;
    
    }
};