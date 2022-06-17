class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int inc = 1, dec = 1;
        
        for ( int i = 1; i < nums.size(); i++){
            if (nums[i] < nums[i-1]) inc = 0;
            if (nums[i] > nums[i - 1]) dec = 0;
            if(!inc && !dec) return 0;
        }
        
        if (inc || dec) return 1;
        return 0;
    }
};