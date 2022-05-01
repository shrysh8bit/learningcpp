class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int removals = 0;
        int arr_size = nums.size();
        stack<int> arr_values;
        
        for(int i = arr_size - 1; i >= 0 ; i-- ){
            if (nums.at(i) == val){
                removals++;
            }else{
                arr_values.push(nums.at(i));
                // cout<< nums.at(i) << endl;
            }
        }
        
        int stack_size = arr_values.size();
        // cout << "Stack size " << stack_size << endl;
        
        for (int i = 0; i < stack_size; i++){
            nums.at(i) = arr_values.top();
            // cout << nums.at(i) << endl;
            arr_values.pop();
        }
        
        return arr_size - removals;
    }
};