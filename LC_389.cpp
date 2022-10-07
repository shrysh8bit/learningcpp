class Solution {
public:
    char findTheDifference(string s, string t) {
        int i = 0;

        for (char c : s){
            i = i ^ c;
        }

        for (char c : t){
            i = i ^c;
        }

        return (char)i;
    }
};
