#include<iostream>
#include<vector>
#include<stack>

using namespace std;


string reverseWords(string s) {
    stack<char> stk;
    string ans, a;
    
    for ( int i =0; i < s.size(); i++){
        
        if(s[i] == ' '){
            while(!stk.empty()){
            	a = stk.top();
                ans += a;
                stk.pop();
            }
        	
        	ans += ' ';

        }else{
            stk.push(s[i]);
            
        }
    }
    while(!stk.empty()){
    	a = stk.top();
    	// cout << a << endl;
        ans += a;
        stk.pop();
    }
    
    // cout << ans << endl;
    return ans;
}


int main(){
    string s = "Let's take LeetCode contest";
    string ans;
	ans = reverseWords(s);

	// cout << ans << endl;

    return 0;
}