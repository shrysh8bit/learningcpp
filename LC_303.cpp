class NumArray {
public:
    vector <int> added;
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            added.push_back(nums[i] + sum);
            sum = nums[i] + sum;
        }
    }

    int sumRange(int left, int right) {
        if ( left == 0) return added[right];
        return added[right] - added[left - 1];
    }
};
