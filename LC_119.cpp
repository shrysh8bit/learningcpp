#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<int> temp;
        vector<vector<int>> final;
        
        temp.push_back(1);
        final.push_back(temp);
        
        if ( rowIndex == 1) return temp;
        
        temp.push_back(1);
        final.push_back(temp);
        
        if(rowIndex == 2) return temp;
        
        temp.clear();
        
        for ( int i = 3; i <=  rowIndex; i++){
            temp.clear();
            temp.push_back(1);
            for (int j = 0; j < i-2; j ++){
                temp.push_back( final[i-2][j] + final[i-2][j+1] );
            }
            temp.push_back(1);
            final.push_back(temp);
        }
        
    return temp;
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