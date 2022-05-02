class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int arr_size = arr.size();
        int curr, result;
        
        for (int i = 0; i < arr_size; i++){
            curr = arr.at(i) + arr.at(i);
            result = binSearch(arr, 0, arr_size - 1, curr);
            
            if (result >= 0 && result != i){
                return true;
            }
        }
        return false;
    }
    
    
    int binSearch(vector<int>& arr,int left,int right,int val){
        if (left > right){
            return -1;
        }
        
        int mid = (left + right)/2;
        int result;
        
        if (arr[mid] == val){
            return mid;
        }
        else if(arr[mid] > val){
            right = mid - 1;
            result = binSearch(arr, left, right, val);
            return result;
        }
        else if(arr[mid] < val){
            left = mid + 1;
            result = binSearch(arr, left, right, val);
            return result;
        }
        
        return -1;
    }
};