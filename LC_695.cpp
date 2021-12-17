#include<iostream>
#include<vector>
#include<map>

using namespace std;

    
int area (vector<vector<int>>& grid, int i, int j, int& size, int size_r, int  size_c){
    size++;
	grid[i][j] = 0;

    if((i - 1) >= 0 &&   grid[i - 1][j] == 1 ){
        area(grid, (i-1), j, size, size_r, size_c);
    }
    
    	// cout << "call 2" << endl;
    if((j - 1) >= 0 &&  grid[i][j - 1] == 1){
        area(grid,i , j - 1, size, size_r, size_c);
    }
    
    	// cout << "call 3" << endl;
    if( (i + 1) < size_r && grid[i + 1][j] == 1){
        area(grid, i+1, j, size, size_r, size_c);
    }
    
    	// cout << "call 4" << endl;
    if((j + 1) < size_c && grid[i][j + 1] == 1){
        area(grid, i, j + 1, size, size_r, size_c);
    }

    return size;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max = 0, size, area_temp;
    int size_r = grid.size(), size_c = grid[0].size();
    
    for ( int i =0; i< size_r; i++){
        for (int j = 0; j < size_c; j++){
            if (grid[i][j] != 0 ){
            	// cout << "call " << i << " " << j << endl;

	            size = 0;
	            area_temp =  area(grid, i,j, size, size_r, size_c);

	            // cout << "return " << area_temp << endl;
	            if(area_temp > max) max = area_temp;
            } 
        }
    }
    
    return max;
}

int main(){
 	vector<vector<int> > grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
 	
 	// cout << grid.size() << " "<< grid[0].size() << endl;

 	for ( auto pr : grid){
 		for (auto ir : pr){

 			cout << ir << " ";
 		}
 		cout << endl;
 	}
 	cout << endl;

 	int area = maxAreaOfIsland(grid);

 	cout << endl<< area << endl;



	return 0;
}