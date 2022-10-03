class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        vector<int> a1(150, 0);
        vector<int> a2(150, 0);

        for (int i = 0; i < s1.size();i++){
            if (s1[i] != s2[i]) {
                count++;
                a1[(int)s1[i]]++;
                a2[(int)s2[i]]++;
            }

            if(count > 2) return 0;
        }

        if((count == 2 && a1 == a2) || count == 0) return 1;
        return 0;
    }
};