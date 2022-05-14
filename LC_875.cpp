class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 0, mid;

        for (int i : piles){
            right = max(i, right);
        }


        int piles_eaten, num_piles = piles.size() - 1;
        int hours;
        int break_condn = 0;
        double j;

        while (left < right){
            mid = left + (right - left)/2;

            piles_eaten = 0;
            hours = 0;

            for (int i : piles){
                j = i;
                hours += ceil(j/mid);
                piles_eaten++;

                // cout << j << " " << mid << " " << j/mid << " " << ceil(j/mid) << endl;
                // cout << left << " " << right << " " << hours << " " << j << " " << ceil(j/mid) << " " << mid << endl;
                if (hours > h){
                    break_condn = 1;
                    break;
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
