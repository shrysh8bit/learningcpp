#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

void bubble( vector<pair<string, int>>& vec){

    for ( int j = 0; j < vec.size() - 1; j++){

        for ( int i = 1; i < vec.size() - j ; i++){
            if ( vec[i - 1].second < vec[i].second ){
                pair<string, int> temp = vec[i];
                vec[i] = vec[i - 1];
                vec[i-1 ] = temp;
            }
        }
    }
}

vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> str_map;
        vector<pair<string, int>> vec;
        vector<string> final;
        
        for ( auto pr : words){
            str_map[pr] += 1;
        }

        for ( auto pr : str_map){
            vec.push_back(make_pair(pr.first, pr.second ));
        }
        

        bubble(vec);
        // stable_sort(vec.begin(), vec.end(), greater<>());

        for ( int i = 0; i < k; i++){
            final.push_back(vec[i].first);
        }

        for ( auto pr : final){
            cout << pr << "  ";
        }

        return final;
    }




int main(){
    // vector<string> ans, words = {"i","love","leetcode","i","love","coding"}; 
    vector<string> ans, words = {"the","day","is","sunny","the","the","the","sunny","is","is"}; 

   int k = 4;
   ans = topKFrequent(words, k);

    return 0;
}