class Solution {
public:
    int findMin(vector<int>& nums) {
        int left  = 0, right = nums.size() - 1, mid;
        
        while (left < right){
            mid = left + ( right - left)/2;
            
            // cout << left << " " << mid << " " << right << endl;
            
            if (nums[left] < nums[right]){
                right = mid;
            }else if (mid == left || nums[mid] > nums[left]){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        
        return nums[left];
    }
};