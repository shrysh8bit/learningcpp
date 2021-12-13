#include <iostream>

using namespace std;


int main(){

    string s = "leetcode";
    if ( s.size() == 1) return 1;

    int max = 0, count = 1;

    for ( int i = 1; i < s.size(); i++){
        if (s[i] == s[i -1]){
            count++;
        }else{
            count = 1;
        }
        if ( count > max){
            max = count;
        }
    }
   
    cout << max << endl;



    return 0;
}