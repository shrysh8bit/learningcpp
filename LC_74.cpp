#include<iostream>
#include<vector>

using namespace std;




bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int>::iterator it;
        
        for (int i = 0 ; i < matrix.size(); i ++ ){
            if( ( *(matrix[i].begin()) <= target ) && (target <= *(matrix[i].end() -1)) ){

                for (it = matrix[i].begin(); it != matrix[i].end(); it++){
                    if ( *it == target){
                        return true;
                    }
                    
                    if( *it > target){
                        return false;
                    }
                }
            }
        }


        return false;
}

int main(){
	// vector<vector<int>> nums = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    vector<vector<int>> nums = {{1,3,5}, {6,7,8}};
    int target = 8;
    bool result;
    result = searchMatrix(nums, target);
	
    cout << result << endl;



	return 0;
}