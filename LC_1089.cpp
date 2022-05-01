class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        queue<int> nums;
        int num;
        
        for (int i = 0 ; i < arr.size(); i++){
            if (arr.at(i) == 0){
                nums.push(0);
                nums.push(0);
                
            }else{
                nums.push(arr.at(i));
            }
            
            arr.at(i) = nums.front();
            nums.pop();
        }
    }
};
