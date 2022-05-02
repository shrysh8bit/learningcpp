class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int greatest = -1, curr;
        
        for ( int i = arr.size() -1; i >= 0 ; i--){
            curr = arr[i];
                        
            arr[i] = greatest;
            
            if (curr > greatest){
                greatest = curr;
            }
        }
        return arr;
    }
};