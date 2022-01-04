#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<math.h>

using namespace std;

int nextGreaterElement(int n) {
    vector<int> unsorted;
        bool swap_carried = 0;
        int temp = 0;

        while (n > 0){
            unsorted.push_back(n%10);
            n = n/10;
        }
        reverse(unsorted.begin(), unsorted.end());

        vector<int>::iterator it = unsorted.end() -1, rt = it ;

        for (; it > unsorted.begin(); it-- ){
            if (*it > *(it - 1)){
                
                
                for (; rt >= it; rt--){
                
                    if ( *rt > *(it-1) ){
                        swap(*rt, *(it-1) );
                        // rt = unsorted.end();
                        swap_carried = 1;
                        break;
                    } 
                }
                sort(it, unsorted.end());
                break;
            }
        }

        if(!swap_carried) return -1;

        int i =0;
        for (it = unsorted.end() - 1 ; it != unsorted.begin() -1 ;it--  ){
            temp += ( *it )*pow(10,i);
            // i = i*10;
            i++;
        }

        cout << temp + 1 << endl;
        if (temp + 1 < 0) return -1;
        return temp;
}



int main(){
    // int a, n = 32154325;
    int a, n = 2147483647;

    a = nextGreaterElement(n);
    cout << a << endl;


    // vector<int> nums{1,2,3,4,5,6};
    // vector<int>::reverse_iterator it = nums.rbegin();
    // for (it; it != nums.rend(); it++ ){
    //     cout << *it << "    ";
    // }
    return 0;
}