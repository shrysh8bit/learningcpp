class Solution {
public:
    vector<int> posn;
    
    void linear_search(vector<int>& nums, int mid){
        int target = nums[mid], temp = mid;
        int min_index = mid, max_index = mid;
        
        
        
        while (++mid < nums.size() ){
            if(nums[mid] == target ){
                max_index = mid;
            }else{
                break;
            }
        }
         while(--temp >= 0){
            if (nums[temp] == target){
                min_index = temp;
            }else{
                break;
            }
         }
        
        posn.push_back(min_index);
        posn.push_back(max_index);
        
        
    }
        
    
    void binary_search (vector<int>& nums, int target, int left, int right){
        
        while (left <= right){
            
            int mid = (left + right)/2;
            
            if (nums[mid] == target){
                
                linear_search(nums, mid);
            }
            
            if(target < nums[mid]){
                right = mid - 1;
            }else{
                left = mid +1;
            }
            
            }
       }
   
                   
                   
    
    vector<int> searchRange(vector<int>& nums, int target) {
        binary_search(nums, target, 0 , nums.size() -1);
        
        
        if (posn.size() > 1){
            sort(posn.begin(), posn.end());
            posn.erase(posn.begin() + 1, posn.end() -1);
        }else{            
            posn.push_back(-1);
            posn.push_back(-1);
        }
        
        return posn;
    }
};