class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = 46341, mid;

        while (left < right){
            mid = left + (right - left)/2;

            if (mid*mid == x){
                return mid;
            }else if (mid*mid > x){
                right = mid;
            }else{
                left  = mid + 1;
            }
        }

        return left - 1;

    }
};
