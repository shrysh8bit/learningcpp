#include<iostream>
#include<vector>

using namespace std;

vector<int> ans;


void binary_left(vector<int>& nums, int target) {
     int index = -1;
     int left = 0, right = nums.size() -1;

     while(left < right){
        int mid = (left + right)/2;

        if(target < nums[mid]){
            right = mid - 1;
        }else if (nums[mid] < target){
            left = mid + 1;
        }
        
        if(nums[mid] == target){
            index = mid;
            right = mid - 1;
        }
     }

    if (left == right && nums[left] == target) index = left;

    ans.push_back(index);
}

void binary_right(vector<int>& nums, int target) {
    
    int index = -1;
    int left = 0, right = nums.size() -1;

    while(left < right){
        int mid = (left + right)/2;

        if(target < nums[mid]){
            right = mid - 1;
        }else if (nums[mid] < target){
            left = mid + 1;
        }
        
        if(nums[mid] == target){
            index = mid;
            left = mid + 1;
        }
    }

    if (left == right && nums[left] == target) index = left;

    ans.push_back(index);

}


vector<int> searchRange(vector<int>& nums, int target) {
    
    binary_left(nums, target);

    binary_right(nums, target);
    

    return ans;
}


int main(){

    vector<int> nums {};
    int target = 1;

    searchRange(nums, target);


    return 0;
}
