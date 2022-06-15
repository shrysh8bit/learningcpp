class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        int size;
        
        for(int i = 0; i < nums.size(); i++){
            size = result.size();
            
            for (int j = 0; j < size; j++){
                
                result.push_back(result[j]);
                result.back().push_back(nums[i]);
            }
        }
        
             
        return result;
    }
};