#include<iostream>
#include<vector>

using namespace std;


int binary_search(vector<int>& nums, int& target, int left, int size){
	int rt = 2 * left;

	cout << "new call" << endl;

	while(left != size){

		cout << nums[left]<< " " << nums[rt]<< " "<< size<<  endl;
		
		if (rt >= size) {
			rt = size-1;
		}


		if (nums[left] <= nums[rt]){
				
				if (nums[left] == target){
					return left;
				}

				if (nums[rt] == target){
					return rt;
				}
			if (nums[left] <= target && target <= nums[rt]){

				return binary_search(nums, target, ++left, rt);
			}
		}

		if(nums[left] >= nums[rt]  && left != rt){
				
				if (nums[left] == target){
					return left;
				}

				if (nums[rt] == target){
					return rt;
				}
				
			if(nums[left] < target || target < nums[rt]){
				return binary_search(nums, target, ++left, rt);

			}
		}

		left = rt + 1;
		rt = 2 * left;

	}

	return -1;
}

int search(vector<int>& nums, int target) {

	if(nums.size() == 1 && nums[0] == target){
		return 0;
	}

	int result = binary_search(nums, target, 0, nums.size());

	cout << result << endl;
	return result;
}

int main(){
	vector<int> nums {4,5,6,7,0,1,2};
	int index, target = 0;

	index  = search(nums, target);    

    return 0;
}