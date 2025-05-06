#include <iostream>
using namespace std;
int binary (){
	int decimal=10,pow=1,binary=0,rem;
	
	while(decimal>0){
		rem=decimal%2;
		decimal/=2;
		binary+= rem *pow;
		pow*=10;
	}
	return binary;
}
int decimal(){
	int binary=101,pow=1,decimal,rem;
	while(binary>0){
		rem=binary%2;
		binary/=10;
		pow*=2;
		decimal+= pow*rem;
	}
	return decimal;
}
int main() {
    cout << (10>>1);
    return 0;
}

