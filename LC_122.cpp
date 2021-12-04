class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>::iterator it, it_ref = prices.begin(), it_trail = prices.begin();
        int profit = 0;
        
        for (it = prices.begin(); it != prices.end(); it++){
            if(*it > *it_trail){
                profit += (*it - *it_trail);
            }
            it_trail = it;
        }
    return profit;
    }
};