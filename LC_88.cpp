#include<iostream>
#include<vector>
#include<map> 

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       	int count = m+n;
        vector<int> temp;
        temp.resize(0);

        vector<int>::iterator it = nums1.begin(), it2 = nums2.begin();
        for (int i = 0; i < m ; i++){
        	temp.push_back(*it);
        	it++;
        }

        nums1.clear();
		
		vector<int>::iterator it1= temp.begin();
	    while ( count > 0){
	        if (it1 != temp.end() && it2 != nums2.end()){
	        	if ( *it1 <= *it2){
	        		nums1.push_back(*it1);
	        		it1++;
	        	}else{
	        		nums1.push_back(*it2);
	        		it2++;
	        	}
	        	count--;
	        }
	        if( it1 == temp.end()){
	        	nums1.push_back(*it2);
	        	count--;
	        	it2++;
	        }else if(it2 == nums2.end()){
	        	nums1.push_back(*it1);
	        	it1++;
	        	count--;
	        }
	    }




        for (auto pr : nums1){
		cout << pr << endl;
	}
    }

int main(){
	vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2,5,6};
	int m = 3, n = 3;

	merge(nums1, m, nums2, n);

	// for (auto pr : nums1){
	// 	cout << pr << endl;
	// }


	return 0;
}


