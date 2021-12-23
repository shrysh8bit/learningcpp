#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool rotateString(string s, string goal) {
        if ( s.size() != goal.size()) return false;

        goal += goal;
        // cout << goal << " " << goal.size()<<  endl;
        
        int i_g = 0, len = goal.size();
    	int  i_s, count = 0;
    	// bool match, diff = 1;

        for (int i = 0; i <= len/2; i++) {
        	i_g = i;
        	i_s = 0;
        	count = 0;
      //   	cout << "new comparision" << endl;
    		// cout << s[i_s]<< " " << goal[i_g] << " " << count << endl;

        	while (s[i_s] == goal[i_g]  && i_s < (len/2) ) {
        		// cout << s[i_s]<< " " << goal[i_g] << " " << count << endl;
        		i_s++;
        		i_g++;
        		count++;
        	}

        	if(count >= (len/2)) return true;

        }
        
        return false;
        
    }

int main(){
	string s1 = "abcde";
	string s2 = "abced";


	cout << s1.size() << endl;
	bool ans = rotateString(s1, s2);

	cout << ans << endl;


    return 0;
}

