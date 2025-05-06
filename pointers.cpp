#include<iostream>
using namespace std;

void add(int &x,int &y){
		cout <<x+y;
	
}
int main(){
	int a=10;
	int b=10;
	int *x=&a,*y=&b;
	add(*x,*y);
	return 0;
}