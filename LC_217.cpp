class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 1){
            return false;
        }
        
        vector<int>::iterator it_lag = nums.begin(), it_lead = (nums.begin() + 1);
        
        for (it_lag = (nums.begin()); it_lag < (nums.end()); it_lag++ ){
            for ( it_lead = it_lag + 1; it_lead< nums.end(); it_lead++){
                if (*it_lag == *it_lead){
                    return true;
                }
            }
        }
        
        
        
        return false;
    }
};