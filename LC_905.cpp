class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int vec_size = nums.size();
        int front = 0, back = vec_size - 1, temp;
        
        while (front < back){
            while (front < vec_size && nums[front] % 2 == 0){
                front++;
            }
            
            while (back >= 0 && nums[back]%2 != 0){
                back--;
            }
            
            if (front < back){
                
                temp = nums[front];
                nums[front] = nums[back];
                nums[back] = temp;

                front++;
                back--;
            }
        }
    return nums;
    }
};