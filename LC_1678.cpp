class Solution {
public:
    string interpret(string command) {
        string result;
        int i = 0;

        while(i < command.size()){
            if (command[i]== 'G'){
                result += 'G';
            }else if(command[i+1] == ')'){
                result += 'o';
                i++;
            }else{
                result += "al";
                i += 3;
            }

            i++;

        }

        return result;
    }
};
