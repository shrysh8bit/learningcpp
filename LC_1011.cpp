class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int total_wt = 0, max_indl_wt = 0;
        for(int i: weights){
            total_wt += i;
            max_indl_wt = max(max_indl_wt, i);
        }

        int min_wt = ceil(total_wt/days), max_wt = total_wt, max_bucket = max_wt;
        min_wt = max(min_wt, max_indl_wt);
        int left = min_wt, right = max_wt, mid;
        int count, curr_wt, break_condn = 0;



        // cout << min_wt << " " << max_wt << " " << days << endl;

        while(left < right){
            mid = left + (right - left)/2;

            // cout << "TOP " << left << " " << right << " " << mid << endl;
            count = 1;
            curr_wt = 0;

            for ( int i : weights){

                // cout << "mid " << count << " " << curr_wt << " " << i << endl;
                if (curr_wt + i > mid){
                    curr_wt = i;
                    count++;
                    if (count > days){
                        left = mid + 1;
                        // count = 1;
                        // curr_wt = 0;
                        break_condn = 1;
                        break;
                    }
                }else{
                    curr_wt += i;
                }
            }
            if (break_condn){
                break_condn = 0;
                continue;
            }
            right = mid;

            max_bucket = min(mid, max_bucket);
            // cout << " Bottom " <<  max_bucket  << " " << left << " " << right << endl;

        }





        return max_bucket;
    }
};
