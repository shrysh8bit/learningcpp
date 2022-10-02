class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort (nums.begin(), nums.end());
        int r = nums.size() - 1;
        int m = r-1, l = r-2;

        while (l>=0){
            if(nums[r] < (nums[m] + nums[l])) {
                return nums[r] + nums[m] + nums[l];
            }else{
                r = r - 1;
                m = r - 1;
                l = m-1;
            }
        }

        return 0;
    }
};