#include<iostream>
#include<vector>

using namespace std;



vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        if (mat.size() * mat[0].size() != r * c){
            return mat;
        }
        
        vector<int> temp;
        vector<vector<int>> final;
        int i, j , count = 0;
        
        for ( i = 0; i < mat.size(); i++){
            for ( j = 0; j < mat[i].size(); j++){
                count++;
                temp.push_back(mat[i][j]);
                if ( count % c == 0){
                    final.push_back(temp);
                    temp.clear();
                }
            }
        }
        
        
        return final;
}


int main(){
	vector<vector<int>> mat = {{1,2,3}, {2,3,4}}, final;
	int r = 1, c = 4;
	final = matrixReshape(mat, r, c);
	// for (int row = 0; row < mat.size(); row++){
	// 	for ( int column = 0; column < mat[row].size(); column++){

	// 	cout << mat[row][column] << " ";
	// 	}
	// 	cout << endl;
	// }

	// cout << mat.size()* mat[0].size() << endl;


	return 0;
}