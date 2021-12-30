class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        vector<pair<int,int>> row;
        
        for ( int i = 0; i < matrix.size(); i++){
            for ( int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j] == 0){
                    row.push_back({i,j});
                }
            }
        }
        
        for ( auto pr : row){
            for (int j = 0; j < matrix[0].size(); j++){
                matrix[pr.first][j] = 0;
            }
        }
        
        for ( auto pr : row){
            for (int j = 0; j < matrix.size(); j++){
                matrix[j][pr.second] = 0;
            }
        }
        
   }
};