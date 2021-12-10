#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isValid(string s) {
	
	stack<char> stk;
	
	for ( int i = 0; i < s.length(); i++){

		if( s[i] == ')' ){
			if(!stk.empty() && stk.top() == '(') {
				stk.pop();
			}else{
				return false;
			}
		}

		if(s[i] == ']' ){
			if(!stk.empty() && stk.top() == '[') {
				stk.pop();
			}else{
				return false;
			}
		}

		if(s[i] == '}' ){
			if(!stk.empty() && stk.top() == '{') {
				stk.pop();
			}else{
				return false;
			}
		}

		if( s[i] == '(' || s[i] == '[' || s[i] == '{'){
			stk.push(s[i]);
		}
		
	}

	if ( stk.empty() == false) return false;

	return true;
}


int main(){
	string str = "]";
	bool answer;

	answer = isValid(str);
	cout << answer << endl;



	return 0;
}