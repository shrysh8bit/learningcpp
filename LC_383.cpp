#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> umap_mag;
    for (int i = 0; i < magazine.size(); i++){
        umap_mag[magazine[i]] += 1;
    }

    for ( int i = 0; i < ransomNote.size(); i++){
        if (umap_mag[ransomNote[i]] == 0) return false;
        else{ 
            umap_mag[ransomNote[i]]--;
        }
    }

    return true;

}


int main(){
    string ransomNote = "aaaqb", magazine = "aaaaabbbbbbccccccb";
    bool possible;

    possible = canConstruct(ransomNote, magazine);

    cout << possible << endl;

    return 0;
}