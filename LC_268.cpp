class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int start = 0, temp, i, size = nums.size();

        while (start < nums.size()){

            if(nums[start] != start  && nums[start] < size){

                temp = nums[nums[start]];
                nums[nums[start]] = nums[start];
                nums[start] = temp;


            }else{
                start++;
            }
        }


        for (i = 0; i < nums.size(); i++){
            if (nums[i] != i) return i;
        }

        return i;
    }
};
