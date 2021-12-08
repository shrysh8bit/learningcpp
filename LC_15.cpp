#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> answer;
    vector<int> ans_temp;
    map<vector<int>, int> ans_single;
    sort(nums.begin(), nums.end());

    // for ( auto pr : nums){
    //     cout << pr << " ";
    // }
    // cout << endl;
    int found = 0;
    int left, right;
    for ( int i = 0; i < nums.size(); i++){
        // while (nums[i] == nums[i-1]){
        //     i++;
        // }
        
        left = i + 1;
        right = nums.size() - 1;
        found = 0;

        while ( left < right){

            if ( (nums[left] + nums[right]) == (-nums[i])){
                ans_temp.push_back(nums[i]);
                ans_temp.push_back(nums[left]);
                ans_temp.push_back(nums[right]);
                // answer.push_back(ans_temp);
                ans_single[ans_temp] = 1;
                ans_temp.clear();
                // found = 1;
            }
            // cout << "i  " << nums[i] << "  l " << nums[left] << "   r: " << nums[right] << endl;

            if (nums[i] + nums[left] + nums[right] >= 0){
                right--;
            }

            if (nums[i] + nums[left] + nums[right] < 0){
                left++;
            }
        }
    }

    for ( auto pr : ans_single){
        answer.push_back(pr.first);
    }

    for ( auto pr : answer){
        for ( auto it : pr){
            cout << it << " ";
        }
        cout << endl;
    }


    return answer;        
    
}




int main(){
    vector<int> nums = {-2,0,1,1,2};
    vector<vector<int>> answer;

    answer = threeSum(nums);
    cout << answer.size() << endl;




    return 0;
}