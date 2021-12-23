#include<iostream>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int count;

    for(int i = 0; i < nums.size() - 1; i++){
        // cout << i << endl;
        if(nums[i] == nums[i+1]){
            nums[i] = -101;
        }
    }

    int j = 0;
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] != -101){
            nums[j] = nums[i];
            j++;
        }
    }

    for( auto pr : nums){
        cout << pr << " ";
    }
    cout << endl;

    return j;
}



int main(){

    vector<int> nums {1,1,1,2,2,2,2,2,2,3,3,3,3,3};
    int count = removeDuplicates(nums);

    cout << count << endl;


    return 0;
}
