class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m*n, mid;

        int count, row_count;

        while (left < right){
            mid = left + (right - left)/2;
            count = 0;


            for (int i = 1; i <= m; i++ ){
                row_count = min(mid/i, n);

                count += row_count;

            }

            if (count >= k){
                right = mid;
            }else{
                left = mid + 1;
            }
        }

        return left;
    }
};
