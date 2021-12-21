#include <iostream>
#include <vector>

using namespace std;


bool search(vector<int>& nums, int target) {

        if (nums.size() == 1 && nums[0] == target) return 1;
        
        int rt = nums.size() - 1;
        int left = 0, mid;
        
        while (left < rt){

            cout << left << " " << rt << endl; 

            mid = (left + rt) / 2;

            if (nums[left] >= nums[mid]){
                if (target >= nums[left] || target <= nums[mid]){
                    if (nums[left] == target) return true;
                    if (nums[mid] == target) return true;
                    rt = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            
            if (nums[left] <= nums[mid]){
                if (nums[left] <= target && target <= nums[mid]){
                    if (nums[left] == target) return true;
                    if (nums[mid] == target) return true;
                    rt = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) return true;
        }
        
        return false;
    }

int main(){

    vector<int> nums {1,0,1,1,1,1};
    bool ans;

    int target = 0;

    ans = search(nums, target);
    cout << ans << endl;


    return 0;
}