class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> greater;
        stack<int> stk;
        vector<int> result;

        for ( int i =  nums2.size() -1 ; i >= 0; i--){
            if(stk.empty()){
                 greater[nums2[i]] = -1;
                 stk.push(nums2[i]);
            }else{
                while(!stk.empty() && stk.top() < nums2[i]){
                    stk.pop();
                }
                if(stk.empty()){
                    greater[nums2[i]] = -1;
                    stk.push(nums2[i]);
                    continue;
                }
                greater[nums2[i]] = stk.top();
                stk.push(nums2[i]);
            }
        }

        for (int i : nums1){
            result.push_back(greater[i]);
        }

        return result;


    }
};
