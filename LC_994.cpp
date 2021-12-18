#include<iostream>
#include<vector>
#include<map>

using namespace std;

int oranges(vector<vector<int>>& grid){

	int row = grid.size(), column = grid[0].size();
	int step = 0, temp;

	vector< int> points, temp_vec;

	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			if ( grid[i][j] == 2) {
				points.push_back(i);
				points.push_back(j);
			}
		}
	}

	while ( !points.empty() ){

		// int i, j;
		// cout << "new round" << endl;

		// for ( int z = 0; z < points.size(); z += 2 ){
		// 	cout << points[z] << " " << points[z + 1] << " " << step <<  endl;
		// }

		temp = 0;

		for (int z = 0; z < points.size(); z += 2){
			// cout << endl;
			// cout << points[z] << " " << points[z+1] << " " << endl;
			// count++;

			int i = points[z], j = points[z + 1];

			if( i + 1 < row && grid[i + 1][j] == 1){
		        grid[i + 1][j] = 2;
		        temp_vec.push_back(i + 1);
		        temp_vec.push_back(j);
		        temp++;
		        // cout << "here 1  " << temp << endl;
		    }

		    if( i - 1 >= 0 && grid[i - 1][j] == 1){
		        grid[i - 1][j] = 2;
		        temp_vec.push_back(i - 1);
		        temp_vec.push_back(j);
		        temp++;
		        // cout << "here 2  " << temp << endl;

		    }

		    if( j + 1 < column && grid[i][j + 1] == 1){
		        grid[i][j + 1] = 2;
				temp_vec.push_back(i);
		        temp_vec.push_back(j + 1);
		        temp++;
				// cout << "here 3  " << temp << endl;

		    }

		    if( j - 1 >= 0 && grid[i][j - 1] == 1){
		        grid[i][j - 1] = 2;
		        temp_vec.push_back(i);
		        temp_vec.push_back(j - 1);
		        temp++;
		        // cout << "here 4  " << temp << endl;

		    }          
		}
	
	    if (temp != 0){
	    	step++;
	    }

		points.clear();

		for ( int i = 0; i < temp_vec.size(); i++){
			points.push_back(temp_vec[i]);
		}
		temp_vec.clear();

	}

	// cout << "final grid: "<< endl;
 //    for ( auto pr : grid){
 //        for ( auto ir : pr){
 //            cout << ir<< " ";
 //        }
 //        cout << endl;
 //    }   
 //    cout << endl;
    

	for ( auto pr : grid){
        for ( auto ir : pr){
            if (ir == 1) return -1;
        }
    }    
    
    if(step > 0){
        return step; 
    }else{
        return 0;
    }
}


int main(){
	vector<vector<int>> grid = {{2,0,1,1,1,1,1,1,1,1},{1,0,1,0,0,0,0,0,0,1},{1,0,1,0,1,1,1,1,0,1},{1,0,1,0,1,0,0,1,0,1},{1,0,1,0,1,0,0,1,0,1},{1,0,1,0,1,1,0,1,0,1},{1,0,1,0,0,0,0,1,0,1},{1,0,1,1,1,1,1,1,0,1},{1,0,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}};
	// vector<vector<int> > grid = {{2,1,1},{1,1,0},{0,1,1}};

	int steps;

	// cout << "initial grid: "<< endl;
 //    for ( auto pr : grid){
 //        for ( auto ir : pr){
 //            cout << ir<< " ";
 //            // if (ir == 1) return -1;
 //        }
 //        cout << endl;
 //    }   
 //        cout << endl;


	steps = oranges(grid);
	cout << "steps: " << steps << endl;

	return 0;
}