#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

void findRelativeRanks(vector<int>& score) {
    vector<string> ans;
    map<int, int, greater<int>> relative;

    for (int pr : score) {
        relative[pr] = 0;
    }

    int i = 1;
    for (auto pr : relative){
        relative[pr.first] = i;
        i++;
    }
    
    for (int pr : score){
        if (relative[pr] == 1) ans.push_back("Gold Medal");
        else if (relative[pr] == 2) ans.push_back("Siler Medal");
        else if (relative[pr] == 3) ans.push_back("Bronze Medal");
        else{
            ans.push_back(to_string( relative[pr] ));
        }

    }

    return ans;

}

int main(){
    vector<int> score {10,3,8,9,4};
    findRelativeRanks(score);

    return 0;
}

