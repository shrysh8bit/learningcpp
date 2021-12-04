class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>::iterator it, it_ref = prices.begin();
        int profit_curr, profit_max = 0;
        for (it = prices.begin(); it != prices.end(); it++){
            profit_curr = ( *it - *it_ref);
            
            if(profit_curr < 0){
                it_ref = it;
            }
            if (profit_curr > profit_max){
                profit_max = profit_curr;
            }
        }
    return profit_max;
    }
};