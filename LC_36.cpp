class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int arr[10] = {0};
        
        for (int i = 0; i < 9 ; i += 3){
            for ( int j = 0; j < 9; j += 3){
                for (int k = i; k < (i + 3); k++){
                    for (int z = j; z < (j + 3); z++){
                        if ( board[k][z] != 46){
                            int a = board[k][z] - '0';
                            if ( arr[a] == 1) return false;
                            arr[a] = 1;
                            // cout << board[k][z]<< " ";
                        }
                    }
                
                }
                for (int a = 0; a < 10 ; a++) arr[a] = 0;
            // cout << endl;
            }
        }
        
        
        
        for ( int i = 0; i < 9 ; i++){
            for ( int j = 0; j < 9 ; j++){
                if ( board[i][j] != 46){        
                    int a = board[i][j] - '0';
                    if ( arr[a] == 1) return false;
                    arr[a] = 1;
                }
            }
            for (int a = 0; a < 10 ; a++) arr[a] = 0;
        }
        
        for ( int j = 0; j < 9 ; j++){
            for ( int i = 0; i < 9 ; i++){
                if ( board[i][j] != 46){        
                    int a = board[i][j] - '0';
                    if ( arr[a] == 1) return false;
                    arr[a] = 1;
                }
            }
            for (int a = 0; a < 10 ; a++) arr[a] = 0;
        }
        
        
    return true;
    }
    
};