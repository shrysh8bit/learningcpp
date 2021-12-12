#include<iostream>
#include <vector>

using namespace std;

int binary(vector<int>& nums, int left, int right, int target){
    int index, mid = (left + right)/2;

    for ( auto pr : nums){
        cout << pr << " " ;
    }

    cout <<" :: " <<mid<< " " << left << " " << right << " " << nums[mid] <<  endl;
    
    if ( left > right) return -1;

    if (nums[mid] == target) return mid;

    if ( nums[mid] > target){
        cout << "smaller fn call" << endl;
        index = binary(nums, left, mid - 1, target);
        return index;
    }

    if ( nums[mid] < target){
        cout << "larger fn call" << endl;
        index = binary(nums, mid + 1, right, target );
        return index;
    }

    // return mid;
    return -1;

}


int search(vector<int>& nums, int target) {
    int left = 0, right = (nums.size() -1);
    int index = -1;
    index = binary ( nums, left, right, target);


    return index;

        
}



int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int index, target = 11;
    index = search(nums, target);
    cout << index << endl;

    return 0;
}