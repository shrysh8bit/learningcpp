#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


bool custom (vector<int>& a, vector<int>& b){
    return (a[0] < b[0]);
}

void merge(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;

    for ( auto pr : intervals){
            cout << pr[0] << " " << pr[1] << "  " << endl;
    }cout << endl;

    int i = 0;
    int left = 0, right = 0;
    bool merge = false;

    while(i < intervals.size()){

        while(i < intervals.size() -1  && (intervals[i][1] >= intervals[i+1][0]  || right >= intervals[i+1][0] ) ){
            
            left = min(left, intervals[i][0]);
            // cout << left << endl;
            left = min (left, intervals[i+1][0]);
            // cout << left << "       " << intervals[i+1][0] << endl;

            right = max(right , intervals[i][1]);
            right = max(right, intervals[i+1][1]);

            i++;
            merge = true;
        }

        if ( merge == true){
            ans.push_back({left, right});
            merge = false;
        }else{
            ans.push_back( { intervals[i][0], intervals[i][1] } );
        }
        i++;
    }
    
    
    for ( auto pr : ans){
            cout << pr[0] << " " << pr[1] << "  " << endl;
    }cout << endl;

    return;       
}

int main(){
	vector<vector<int>> intervals {{2,3},{4,5}, {6,7}, {8,9}, {1,10}};
    merge(intervals);

	return 0;
}