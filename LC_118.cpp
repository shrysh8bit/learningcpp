#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> temp;
        vector<vector<int>> final;
        
        temp.push_back(1);
        final.push_back(temp);
        
        if ( numRows == 1) return final;
        
        temp.push_back(1);
        final.push_back(temp);
        
        if(numRows == 2) return final;
        
        temp.clear();
        
        for ( int i = 3; i <=  numRows; i++){
            temp.push_back(1);
            for (int j = 0; j < i-2; j ++){
                temp.push_back( final[i-2][j] + final[i-2][j+1] );
            }
            temp.push_back(1);
            final.push_back(temp);
            temp.clear();
        }
        
    return final;
    }
};





int main(){

    int numRows = 5, i , j;
    vector<vector<int>> final;

    // cout << final[1].size() << endl;

    final = generate(numRows);

    // for (i = 0; i < final.size(); i++ ){
    //     for ( j = 0; j < final[0].size(); j++){
    //         cout << final[i][j] << " ";
    //     }
    //     cout << endl;
    // }



    return 0;
}