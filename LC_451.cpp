#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<utility>

using namespace std;







int main(){
    string s = "trees", final;
    map<char, int> char_map;
    vector<pair<int, char>> int_vec;

    for ( char pr : s){
        char_map[pr] += 1;
    }


    for ( auto pr : char_map){
        int_vec.push_back(make_pair(pr.second, pr.first));
        // cout << pr.first << " " << pr.second << endl;

    }

    sort(int_vec.begin(), int_vec.end(), greater<>());

    for ( auto pr : int_vec){
        cout << pr.first << " " << pr.second << endl;

        for ( int i = 0 ; i <  pr.first; i++){
            final += pr.second;
        }
    }

    cout << final << endl;




    return 0;
}