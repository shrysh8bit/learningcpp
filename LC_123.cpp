#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
	int max_profit;

	int fb = 999999, fs = 0, sb = 9999999, ss = 0;

	for (int i = 0; i < prices.size(); i++) {
		fb = min(fb, prices[i]);
		fs = max(fs, prices[i] - fb);
		sb = min (sb, prices[i] - fs);
		ss = max(ss, prices[i] - sb);

	}

	return ss;
}


int main(){
	vector<int> prices = {3,3,5,1,0,3,1,4};
	// vector<int> prices = {1,2,3,4,3,6,7,8};
	int profit;

	profit = maxProfit(prices);
	cout << profit << endl;




	return 0;
}