#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>

using namespace std;

// map<pair<int, int>, int> posn;
unordered_map<pair<int, int>, int> posn;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	
	posn[{sr, sc}] = 1;

	int size_r = image.size();
	int size_c = image[0].size();

	int pixel = image[sr][sc];

	image[sr][sc] = newColor;
	
	if ( (sr - 1) >= 0 &&  image[sr-1][sc] == pixel && posn[make_pair(sr -1, sc)] != 1){
		floodFill(image, sr -1 , sc,newColor );
	}

	if ( (sc - 1) >= 0 &&  image[sr][sc-1] == pixel && posn[make_pair(sr, sc - 1)] != 1){
		floodFill(image, sr , sc -1,newColor );
	}

	if ( (sr + 1) < size_r &&  image[sr+1][sc] == pixel && posn[make_pair(sr + 1, sc)] != 1){
		floodFill(image, sr + 1 , sc ,newColor );
	}

	if ( (sc + 1) < size_c &&  image[sr][sc + 1] == pixel && posn[make_pair(sr, sc + 1)] != 1){
		floodFill(image, sr, sc + 1,newColor);
	}

	return image;
}			





int main (){

	vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
	// vector<vector<int>> image = {{0,0,0},{0,1,1}};
	
	int sr = 1, sc = 1, newColor = 2;

	image = floodFill(image, sr, sc, newColor);

	for (auto pr : image){
		for ( auto ir : pr){
			cout << ir << "  ";
		}
		cout << endl;
	}
	return 0;
}