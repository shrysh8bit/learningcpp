class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        // case 1 : all nums positive
        
        if (nums.front() >= 0 && nums.back() >= 0){
            
           for (int itr = 0; itr < nums.size(); itr++){
               nums.at(itr) *= nums.at(itr); 
           }
        return nums;
        
        }
        
        
        //case 2  : all nums negative
        
        if (nums.front() < 0 && nums.back() < 0){
            reverse (nums.begin(), nums.end());
            
            for (int itr = 0; itr < nums.size(); itr++){
               nums.at(itr) *= nums.at(itr); 
           }
        return nums;
        }
        
        
        //case 3 : +ve and -ve mixed
        
        int fwd_itr, reverse_itr;
        
        for (int itr = 0 ; itr < nums.size(); itr++){
            if (nums.at(itr) >= 0){
                fwd_itr = itr;
                reverse_itr = itr - 1;
                break;
            }
        }
        
        vector<int> abs_sorted_vec;
        int nums_size = nums.size();
        
        while (fwd_itr < nums_size || reverse_itr >= 0){
            
            if (fwd_itr < nums_size && reverse_itr >= 0){
                if ((nums.at(fwd_itr)) <= abs(nums.at(reverse_itr)) ){
                    
                    abs_sorted_vec.push_back(nums.at(fwd_itr));
                    fwd_itr++;
                }else{
                    
                    abs_sorted_vec.push_back(abs(nums.at(reverse_itr)));
                    reverse_itr--;
                }
            }

            else if (fwd_itr >= nums_size){
                abs_sorted_vec.push_back(abs(nums.at(reverse_itr)));
                reverse_itr--;
            }

            else if (reverse_itr < 0){
                abs_sorted_vec.push_back(abs(nums.at(fwd_itr)));
                fwd_itr++;
            }
            
            
        }
        
       for (int itr = 0; itr < abs_sorted_vec.size(); itr++){
               abs_sorted_vec.at(itr) *= abs_sorted_vec.at(itr); 
       }

        return abs_sorted_vec;
        
        
    }
};
