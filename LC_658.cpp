class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() -1, mid;

        while (l < r){
            mid = (r + l)/2;

            if (arr[mid] < x){
                l = mid + 1;
            }else if (arr[mid] == x){
                break;
            }else{
                r = mid;
            }
        }

        l = max(0, mid- k);

        // cout << mid << " " << k << endl;
        if (arr.size() - 1 < mid + k){
            r = arr.size() - 1;
        }else{
            r = mid + k;
        }

        // cout << l << " " << mid << " " << r << endl;
        while ( r - l >= k ){
            if (abs(arr[l] - x) < abs(arr[r] - x) ||
            (abs(arr[l] - x) == abs(arr[r] - x) && arr[l] < arr[r])){
                r--;
            }else{
                l++;
            }
        }

        vector<int> result;

        for (int i = l ; i <= r; i++){
            result.push_back(arr[i]);
        }

        return result;


    }
};
