#include<iostream>
#include<vector>

using namespace std;




vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>::iterator it_lag, it_lead;
        vector<int> returnvec;
        int count1 = -1, count2;
        
        for (it_lag = nums.begin(); it_lag != nums.end(); it_lag++){
        	count1++;
        	count2 = count1;
            for ( it_lead = it_lag + 1; it_lead != nums.end(); it_lead++ ){
                count2++;
                if ((*it_lag + *it_lead) == target ){
                	cout << *it_lag << " " << *it_lead << endl;
                    returnvec.push_back(count1);
                    returnvec.push_back(count2);
                    return returnvec;
                    
                }
            }
        }
     return returnvec;   
    }

int main(){
	vector<int> nums = {3,2,4}, returnvec;


	returnvec = twoSum(nums, 6);

	cout << *returnvec.begin() << " "<< *(returnvec.end() - 1) << endl;




	return 0;
}