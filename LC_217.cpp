#include<iostream>

using namespace std;


int twoEggDrop(int n) {
	int i = 0;
	while ((i*(i+1)/2) < n  ){
		i++;
	}
	return i;
}


int main(){
	int n = 11, drops;
	drops = twoEggDrop(n);

	cout << drops << endl;


	return 0;
}