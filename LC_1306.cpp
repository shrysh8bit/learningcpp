#include<iostream>
#include<vector>

using namespace std;

vector<int> arr_index;
// int arr_index[arr.size()] = {0};

bool canReach(vector<int>& arr, int start) {
    if (arr_index[start] == 1) return false;
    arr_index[start] = 1;
    
    if ( arr[start] == 0) return true;

    bool answer_l = false, answer_r = false;
    int left, right;
    left = start - arr[start];
    right = start + arr[start];

    if ( left >= 0){
        answer_l = canReach(arr, left);
    }

    if ( right < arr.size()){
        answer_r = canReach(arr, right);
    }

    return (answer_l || answer_r);

}




int main(){
    vector<int> arr = {2,2,3,2,3};
    arr_index.resize(arr.size());
    // cout << arr.size() << endl;
    int start = 3;
    bool answer;
    // cout << "call canreach" << endl;
    answer = canReach(arr, start);


    cout << answer << endl;

    return 0;
}