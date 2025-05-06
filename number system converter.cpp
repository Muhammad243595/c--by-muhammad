#include<iostream>
using namespace std;


long long decimalToBinary (int n){
	if (n==0){
		cout <<"0"<<endl;
	}
	long long binary=0;
	int place=1;
	while (n>0){
		short int remainder=n%2;
		binary+=remainder*place;
		n/=2;
		place*=10;
	}
	return binary;
}
int binaryToDecimal(long long binary){
	int decimal;
	
	
	return decimal;
}
int main (){
	int decimal;cin>>decimal;
	cout<<"Binary equvalent equals to: "<<decimalToBinary (decimal);
	
	return 0;
}