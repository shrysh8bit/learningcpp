#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void nextGreaterElements(vector<int>& nums) {
    int a, s = nums.size();
    vector<int> ans(s,-1);
    stack<int> elements;

    for (int i = 2*(s) - 1; i >= 0; i--){
        a = i%s;
        cout << a << " " << nums[a] << "    ";
        while(!elements.empty() && elements.top() <= nums[a] ){
            elements.pop();
        }

        if( elements.empty() ){            
            ans[a] = -1;
        }else{
            ans[a] = elements.top();
            // if (ans[a] < 0) ans[a] += s;
        }
        cout << ans[a] << endl;
        elements.push(nums[a]);
    }

    for(int pr : ans) {
    cout << pr << " ";
    }cout << endl;

}

int main(){
    vector<int> nums {1,2,3,4,3,2,5,4,8};
    // vector<int> nums {1,2,1};

    nextGreaterElements(nums);

    return 0;
}