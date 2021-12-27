class Solution {
public:
    int findComplement(int num) {
        int number = num, sum = 0, i = 0;
        
        while (number > 0){
            if (number%2 == 0){
                sum += pow(2,i);
            }
            i++;
            number = number / 2;
        }
        
        return sum;
    }
};