class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> vals;
        
        if (tokens.size() == 1) return stoi(tokens[0]);
        
        auto ptr = tokens.rbegin();
        vals.push(*ptr);
        advance(ptr,1);
        
        
        string curr_val, top_val, opr_val;
        char curr, top, opr;
        int result;
        
        for (; ptr != tokens.rend(); ptr++){
            curr_val = *ptr;
            curr = curr_val[curr_val.length() - 1];
            
            top_val = vals.top();
            top = top_val[top_val.length() - 1];
            
            while (isdigit(curr) && isdigit(top)){
                vals.pop();
                opr_val = vals.top();
                opr = opr_val[0];
                vals.pop();
                
                result = mathOpr(stoi(curr_val), stoi(top_val), opr);
                curr_val = to_string(result);
                curr = curr_val[curr_val.length() - 1];
        
                if (vals.empty()) return stoi(curr_val);
                
                top_val = vals.top();
                top = top_val[top_val.length() - 1];
            
            }
            
            vals.push(curr_val);
            
           
            
        }
        return 1;
    }
    
    int mathOpr(int a, int b, char opr){
        switch (int(opr)){
            case 43:
                return a+b;
                break;
                
            case 45:
                return a-b;
                break;
            
            case 42:
                return a*b;
                break;
                
            case 47:
                return a/b;
                break;
                
                
        }
        
        return 0;
    }
};