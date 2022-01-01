#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> greater;
    vector<int> ans;
    
    for ( int i = 0; i < nums2.size(); i++){
        for (int j = i + 1; j < nums2.size(); j++){
            // cout <<nums2[i] << " " << nums2[j] << endl;
            if (nums2[j] > nums2[i]){
                greater[nums2[i]] = nums2[j];
                break;
            }
        }
        if (greater[nums2[i]] == 0 ){            
            greater[nums2[i]] = -1;
        }
    }
    
    for (int i = 0; i < nums1.size(); i++){
        ans.push_back(  (greater[nums1[i]]) );
    }

    return ans;
}

int main(){
    vector<int> nums2 = {1,3,4,2};
    vector<int> nums1 = {4,1,2};

    nextGreaterElement(nums1, nums2);

    return 0;
}