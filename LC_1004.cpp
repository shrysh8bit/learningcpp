class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 1;
        int curr_count = 0, max_count = 0;
        int flip = 0, size = nums.size();


        if(k == 0){
            while (left < size){
                if (nums[left] == 1){
                    curr_count++;
                    max_count = max(curr_count, max_count);
                }else{
                    curr_count = 0;
                }

                left++;

            }
            return max_count;
        }


        if(nums[left] == 0 && flip < k){
            flip++;
        }
        curr_count++;
        max_count = max(curr_count, max_count);

        while(right < size){
            while(flip == k && nums[right] == 0){
                if(nums[left] == 0){
                    flip--;
                }
                left++;
                curr_count--;
            }

            if(nums[right] == 0){
                flip++;
            }

            curr_count++;
            max_count = max(curr_count, max_count);


            right++;
            // cout << left << " " << right << " " << flip << " " << curr_count << " " << max_count << endl;
        }


        return max_count;
    }
};
