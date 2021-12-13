class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> final;
        vector<int> vec;
        unordered_map<int , int> umap_int;
        
        for (auto pr  : nums){
            umap_int[pr] += 1;    
        }
        
        for ( auto pr : umap_int){
            final.push_back(make_pair(pr.second, pr.first));
        }
        
        sort(final.begin(), final.end(), greater<>());
        
        for ( int i = 0; i < k; i++){
            vec.push_back(final[i].second);
        }
        
        return vec;
    }
};