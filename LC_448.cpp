class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int vec_size = nums.size();
        
        vector<int> markers (vec_size, 1);
        vector <int> missing;
        
        
        for (int num : nums){
            markers[num - 1] = 0;
        }
        
        for (int i = 0; i < vec_size; i++){
            if (markers[i] == 1){
                missing.push_back(i + 1);
            }
        }
        
        return missing;
    }
};