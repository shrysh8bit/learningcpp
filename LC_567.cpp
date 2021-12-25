#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<utility>

using namespace std;

bool checkInclusion(string s1, string s2) {
    vector<int> v1(26,0), v2(26,0);

    for ( char pr : s1){
        v1[pr - 'a'] += 1;
    }

    for ( int pr : v1){
        cout << pr << " ";
    }cout << endl;

    for ( int i = 0; i < s1.size() ; i++){
        v2[s2[i] - 'a'] += 1;
    }

    int size1 = s1.size();

    for ( int i = s1.size(); i < s2.size(); i++){
        if(v1 == v2) return true;
        v2[s2[i - size1] - 'a'] -= 1;
        v2[s2[i] - 'a'] += 1;

        for ( int pr : v2){
            cout << pr << " ";
        }cout << endl;

    }

        if(v1 == v2) return true;

    return false;
}
// 

int main(){
    string s1 = "adc";
    string s2 = "dcda";

    bool result = checkInclusion(s1, s2);

    cout << result << endl;



    return 0;
}