class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int carry = 0, temp;

        digits[digits.size() - 1] += 1;

        for (int i = digits.size() - 1; i >= 0; i--){
            digits[i] = digits[i] + carry;
            if (carry == 1) carry = 0;

            if (digits[i] > 9){
                carry = 1;
                digits[i] = digits[i] % 10;
            }
        }

        if(carry){
            reverse(digits.begin(), digits.end());
            digits.push_back(1);
            reverse(digits.begin(), digits.end());

        }

        return digits;
    }
};
