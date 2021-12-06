#include<iostream>
#include<vector>
#include <map>

using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int row = matrix.size(), column = matrix[0].size();
	cout << "row " << row << "   coulumn  " << column << endl;

	for ( int i = 0 ; i < min (row, column); i++){
		cout <<i << "  "<<  matrix[i][i] << endl;
		if (matrix[i][i] >= target){
			for ( int j = 0; j <= i; j++){
				if (matrix[j][i] == target  || matrix[i][j] == target) return true;
			}
			// return false;
		}
	}
	
	for ( int i = min (row, column); i < max (row, column); i++){
		if ( row > column){ //rows > column
			if ((matrix[i][column - 1]) >= target){
				for ( int j = 0; j < column; j++){
					if (matrix[i][j] == target) return true;
				}
			}
		}else{
			if(matrix[row - 1][i] >= target){
				for ( int j = 0 ; j < row; j ++){
					if (matrix[j][i] == target) return true;
				}
			}
		}
	}
	return false;
}



int main(){
	// vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
	// vector<vector<int>> matrix = {{1},{1}};
	vector<vector<int>> matrix = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};

	int row = matrix.size(), column = matrix[0].size();
	cout << row << "  " << column << endl;
	int target = 15;
	bool result;

	// for ( int i = 1; i < 1 ; i++){
	// 	cout << "i is  " << i << endl;
	// }

	result = searchMatrix(matrix, target);

	cout << result << endl;

	return 0 ;
}