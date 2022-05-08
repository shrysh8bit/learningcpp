#include<iostream>
#include <math.h>
using namespace std;

double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n == -1) return 1/x;
    if ( x == 1) return 1;
    
    if (n < 0){
        x = 1/x;
        n = abs(n);
    }

    int odd = 0;
    unsigned int outer = 1;
    if (n % 2 != 0){
        n--;
        odd = 1;
    }

    while (n % 2 == 0){
        n = n/2;
        outer *= 2;
    }
    // cout << x << " " << n << " " << outer << endl;
    double p = n;
    if (odd == 1){
        x = pow(pow(x, p), outer)*x;
    }else{
        x = pow(pow(x, p), outer);

    }

    if (isinf(x) == 1) return 0;
    return x;
}





int main(){

    double x = 21.0000, result;
    int power = -214000;

    result = myPow(x, power);
    cout << result << endl;


    return 0;
}