class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l,r;
        vector<vector<int>> result;
        vector<int> temp;

        for (int i = 0; i < nums.size() -2 ; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            l =  i + 1;
            r = nums.size() -1;

            while ( l < r){
                if(nums[i] + nums[l] + nums[r] == 0){
                    temp.clear();
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    result.push_back(temp);
                    do{
                        l++;
                    }while (l < r && nums[l] == nums[l-1]);

                }else if (nums[i] + nums[l] + nums[r] < 0){
                    do{
                        l++;
                    }while (l < r && nums[l] == nums[l-1]);
                }else{
                    do{
                        r--;
                    }while (l < r && nums[r] == nums[r+1]);
                }
            }
        }

        return result;
    }
};
