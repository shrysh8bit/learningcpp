class Solution {
public:
    
    vector<string> ans;
    
    void generate(string paran, int open, int close){
        if(open == 0 && close == 0){
            ans.push_back(paran);
            return; 
        }
        
        if(open > 0 ){
            paran.push_back('(');
            generate(paran, open - 1, close);
            paran.pop_back();
        }
        
        if ( open < close){
            paran.push_back(')');
            generate(paran, open , close - 1);
        }
        
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        string paran;
        int open = n, close = n;
        
        generate(paran, open, close);
        
        return ans;
    }
};