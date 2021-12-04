class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> common;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int>::iterator it1 = nums1.begin(), it2 = nums2.begin();
    
        while (it1 != nums1.end() && it2 != nums2.end()){
            if (*it1 != *it2){
                if(*it1 < *it2){
                    it1++;
                }else{
                    it2++;
                }
            }else{
                common.push_back(*it1);
                *it1++;
                *it2++;
            }
        }

        return common;
        }
    
};