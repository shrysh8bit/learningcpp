class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 1){
            if (citations[0] >= 1){
                return 1;
            }else{
                return 0;
            }
        }
        
        sort(citations.begin(), citations.end(), greater<>());
        int h_num = 0;
        
        
        for ( int i = 1; i <= citations.size(); i++){
            if(citations[i - 1] >= i){
                h_num = i;
            }else{
                return h_num;
            }
        }

        return h_num;
    }
};