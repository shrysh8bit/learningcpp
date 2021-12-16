class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1) return;
        
        int left = 0, right = 0;        
                
        while(right < nums.size() ){
            while(left < nums.size() && nums[left] != 0) left++;
            if(left == nums.size()) return;
            right = left;
            
            while( right < nums.size() && nums[right] == 0) right++;
            if ( right == nums.size()) return;
            swap(nums[left], nums[right]);
        }
    }
};