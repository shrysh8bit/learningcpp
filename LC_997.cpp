class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> link(n + 1,0);
        // vector<int> judge(n+1,0);
        
        for (auto pr : trust){
            link[pr[1]] += 1;
            link[pr[0]] -= 1;
        }
        
//         for (int pr : link){
//             cout << pr << "   ";
//         }cout << endl;
        
        for (int  i = 1; i <= n; i++ ){
            if (link[i] == n - 1 ) return i;
        }
        
        return -1;
    }
};