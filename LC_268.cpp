class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int src = 0, tgt = 0;

        for ( int  i =0 ; i < nums.size(); i++){
            src ^= i;
            tgt ^= nums[i];
        }

        src ^= nums.size();

        return src^tgt;
    }
};