class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int max = 0, temp;
        int row = matrix.size(), column = matrix[0].size();
        
        for(int i = 0; i < row; i++){
            for (int j = 0; j < column; j++){
                
                // cout << i << " " << j <<  " " << matrix[i][j]<<  endl;
                
                if( matrix[i][j] == '1' ){
                    // cout << "calling area" << endl;
                    temp = 1;
                    temp = area(matrix, i, j, temp, row, column);
                    if (temp > max) max = temp;
                }
                
            }
        }
        return max*max;
            
    }
    
    int area(vector<vector<char>>& matrix, int i, int j, int temp, int row, int column){
        // cout << temp << endl;
        temp++;
        bool sq = true;
        for(int x = 0; x < temp; x++){
            for(int y = 0; y < temp; y++){
                if((i+x) < row && (j+y) < column){
                    
                    if (matrix[i+x][j+y] != '1'){
                        sq = false;
                        temp--;
                        break;
                    }
                }else{
                    temp--;
                    sq = false;
                    break;
                }
                
                
            }
        }
        
        if (sq){
            temp = area(matrix, i , j, temp, row, column);
        }
        
        return temp;   
    }
    
    
};