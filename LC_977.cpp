class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int a= nums.size();
        
        vector<int> result(a, 0);
        
        for ( int i = 0 ; i < a; i++){
            result[i] = (nums[i]*nums[i]);
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};