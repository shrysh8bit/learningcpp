class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size() ){
            string temp = a;
            a = b;
            b = temp;
        }

        int diff = a.size() - b.size();

        for (int i = 0; i < diff; i++){
            b = '0' + b;
        }


        int carry = 0;
        for(int i = b.size() -1  ; i >= 0 ; i--){
            if (a[i] == '0' && b[i] == '0' && carry == 0) {
                carry = 0;
                a[i] = '0';
            }else if( (carry == 0 && a[i] == '1' && b[i] == '1' ) ||
                    (carry == 1 && a[i] == '1' && b[i] == '0' ) ||
                    (carry == 1 && a[i] == '0' && b[i] == '1' )
            ){
                carry = 1;
                a[i] = '0';
            }else if((carry == 1 && a[i] == '1' && b[i] == '1' )){
                carry = 1;
                a[i] = '1';
            }else{
                carry = 0;
                a[i] = '1';
            }
        }

        if(carry){
            a = '1' + a;
        }

        return a;
    }
};