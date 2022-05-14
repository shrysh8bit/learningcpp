class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0, right = 0, mid;

        for (int i : nums){
            left = max(left, i);
            right += i;
        }

        int buckets = 1, curr_wt, break_condn = 0;


        while (left < right){
            mid = left + (right - left)/2;


            curr_wt = 0;
            buckets = 1;

            for (int i : nums){

                if (curr_wt + i <= mid){
                    curr_wt += i;
                }else{
                    curr_wt = i;
                    buckets++;

                    if (buckets > m){
                        break_condn = 1;
                        break;
                    }
                }
            }

            if (break_condn){
                left = mid + 1;
                break_condn = 0;
            }else{
                right = mid;
            }
        }

        return left;
    }
};
