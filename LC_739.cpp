#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

void dailyTemperatures(vector<int>& temperatures) {
    vector<int> days;
        stack<int> temp;

        int count;    
        temp.push(temperatures.back());

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!temp.empty() && temperatures[i] >= temperatures[temp.top()] ){
                temp.pop();
            }

            if (temp.empty()){
                count = 0;
            }else{
                count = temp.top() - i;
            }

            temp.push(i);
            
            days.push_back(count);
        }

        reverse(days.begin(), days.end());



    for ( int pr : days){
        cout << pr << " ";
    }cout << endl;
}

int main(){
    // vector<int> temperatures {73,74,75,71,69,72,76,73};
    vector<int> temperatures {89,62,70,58,47,47,46,76,100,70};

    dailyTemperatures(temperatures);


    return 0;
}