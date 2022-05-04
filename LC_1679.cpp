class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int vec_size = nums.size();
        int front = 0, back = vec_size - 1;
        int pair_count = 0;

        while (front < back){

            if (nums[front] + nums[back] == k){
                pair_count++;
                front++;
                back--;
            }

            if (nums[front] + nums[back] < k){
                front++;
            }

            if (nums[front] + nums[back] > k){
                back--;
            }
        }

        return pair_count;
    }
};
