class Solution {
public:
    unordered_map <int, int> values;
    
    int fib(int n) {
        int result = 0;
        
        if (n == 0) return 0;
        if (n == 1) return 1;

        if (values.find(n) != values.end()){
            return values.at(n);
        } 
        
        result = fib(n - 1) + fib(n - 2);
        
        values.insert({n, result});
        return result;
    }
};