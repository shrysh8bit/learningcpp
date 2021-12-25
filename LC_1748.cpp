class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> dupl(101,0);
        int sum = 0;
        
        for ( int i = 0; i < nums.size(); i++){
            dupl[nums[i]] += 1;
        }
        
        for ( int i = 0; i < nums.size(); i++){
            if(dupl[nums[i]] == 1){
                sum += nums[i];
            }
        }
        
        return sum;
        
    }
};