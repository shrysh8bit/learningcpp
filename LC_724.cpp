class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int rt = 0, left = 0;

        for (int i : nums){
            rt+= i;
        }

        for (int i = 0; i < nums.size() ; i++){
            rt -= nums[i];

            if (left == rt)  return i;

            left += nums[i];
        }

        return -1;

    }
};