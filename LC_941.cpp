class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int arr_size = arr.size();
        
        if (arr_size < 3){
            return false;
        }
        
        int i = 0, count1 = 0, count2 = 0;
            
        for ( ; i < arr_size - 1; i++){
            if (arr[i] == arr[i + 1]){
                return false;
            }
            
            if (arr[i] > arr[i+1]){
                break;
            }
            
            count1++;
        }
        
         if (i == (arr_size - 1)){
             return false;
         }
        
        for (; i < arr_size - 1; i++){
            if (arr[i] == arr[i + 1]){
                return false;
            }
            
            if (arr[i] < arr[i+1]){
                break;
            }
            count2++;
        }
        
        if (i == (arr_size - 1) && count1 >0 && count2 > 0){
            return true;
        }else{
            return false;
        }
    }
};