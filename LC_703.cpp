class KthLargest {
public:
    priority_queue<int, vector<int>> maxhp;
    priority_queue<int, vector<int>, greater<int>> minhp;

    int size;
    KthLargest(int k, vector<int>& nums) {
        size = k;

        for (int i : nums){
            if(minhp.size() < k){
                minhp.push(i);
            }else if(minhp.top() < i){
                    minhp.pop();
                    minhp.push(i);

            }
        }

    }

    int add(int val) {
        if(minhp.size() < size){
                minhp.push(val);
            }else if(minhp.top() < val){
                    minhp.pop();
                    minhp.push(val);

            }

        return minhp.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
