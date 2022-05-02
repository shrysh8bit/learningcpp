class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted;
        int diff = 0;
        
        sorted = heights;
        
        sort(sorted.begin(), sorted.end());
        
        for (int i = 0; i < heights.size(); i++){
            if (heights[i] != sorted[i]){
                diff++;
            }
        }
        
        
        
        return diff;
    }
};