class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        float temp;
        
        int left = 1, right = 0, mid, result;
        
        for (int i : nums){
            right = max(i, right);
        }
        
        while (left < right){
            mid = left + (right - left)/2;
            
            result = 0;
            for (int i : nums){
                temp = i;
                result += ceil(temp/mid);
            }
            
            
            if (result <= threshold){
                right = mid;
            } else{
                left = mid + 1;
            }
        }
    
    return left;
    }
};