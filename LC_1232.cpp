class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) return 1;
        float a,b, c,d;
        for (int i = 0; i <= coordinates.size() - 3; i++){
            a = coordinates[i+1][1] - coordinates[i][1];
            b = coordinates[i+2][1] - coordinates[i+1][1];
            c = coordinates[i+1][0] - coordinates[i][0];
            d = coordinates[i+2][0] - coordinates[i+1][0];

            if (c == 0 && d == 0) continue;

            if ((a/c) != (b/d)) return 0;
        }
        return 1;
    }
};
