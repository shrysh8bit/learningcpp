class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (k*m > bloomDay.size()){
            return -1;
        }

        int left = INT_MAX, right = 0, mid;

        for (int i : bloomDay){
            left = min(left, i);
            right = max (right, i);
        }


        int bouquets, flowers;

        while (left < right){
            mid = left + (right - left)/2;
            // cout << left << " " << right << " " << mid << endl;

            bouquets = 0;
            flowers = 0;


            for (int i : bloomDay){
                if (i <= mid){
                    flowers++;
                    if (flowers == k){
                        flowers = 0;
                        bouquets++;
                    }
                }else{
                    flowers = 0;
                }
            }
            // cout << bouquets << " " << flowers << endl;
            if (bouquets >= m){
                right = mid;
            }else{
                left = mid + 1;
            }
        }

        return left;
    }
};
