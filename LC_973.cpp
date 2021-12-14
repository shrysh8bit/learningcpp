class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>> result;
        vector<vector<int>> ans;
        int dist;
        
        for ( int i = 0; i < points.size(); i++){
            dist =  (points[i][0])*(points[i][0])   +   (points[i][1])*(points[i][1]) ; 
            result.push_back( make_pair(dist, points[i]) )    ;
        }
        
        sort(result.begin(), result.end());
        
        for ( int i = 0; i < k; i++){
            ans.push_back(result[i].second);
        }
        
        return ans;
    }
};