class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string out = "";
        int ptr = 0, size = spaces.size();
        
        for (int i = 0; i < s.size(); i++){
            if(ptr < size && i == spaces[ptr]){
                out += " ";
                ptr++;
            }
            
            out += s[i];
        }
        
        return out;
    }
};