class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)return false;
        
        double val = n;
        
        while(val > 1.5){
            // cout << val << endl;
            val = val/2;
            // cout << val << endl;
                
        }
        
        if (val == 1.0) return true;
        
        return false;
    }
};