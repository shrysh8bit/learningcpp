class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> runs;
        int temp, temp1;
        string ch;
        
        for ( auto pr : ops){
            if ( pr == "C") runs.pop();
            else if ( pr == "D") runs.push( 2*runs.top() );
            else if ( pr == "+"){
                temp = runs.top();
                runs.pop();
                temp1 = temp + runs.top();
                runs.push(temp);
                runs.push(temp1);
            }
            else{
                // ch = pr;
                // cout << pr << endl;
                temp1 = stoi(pr);
                runs.push(temp1);
            }
        }
        
        temp = 0;
        while (!runs.empty()){
            temp += runs.top();
            runs.pop();
        }
        
        return temp;
    }
};