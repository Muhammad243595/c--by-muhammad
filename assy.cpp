#include<iostream>
#include<algorithm>
using namespace std;
//function declarations
void display(short int *option);
void LO3();
void reverseNumber();
int factorial(int num);
int main(){
	short int option;
	display(&option);
	switch (option){
		case 1:
			LO3();
			break;
		case 2:	
			reverseNumber();
			break;
		case 3:
			int num;cout <<"Enter Number: ";cin>>num;
			cout <<factorial(num);
			
		case 11:
			exit(1);
		default:
		cout <<"Invalid choice! TRY AGAIN\n";	
		
	}
	return 0;
}
void display(short int *option){
	cout <<"1.Largest of three\n";
	cout <<"2.Reverse a number\n";
	cout <<"3.Factorial\n";
	cout <<"11.Exit\n";
	cout <<"Enter your choice:";
	cin>>*option;
}
void LO3(){
	int num[3];
	cout <<"1st: ";cin>>num[0];
	cout <<"2nd: ";cin>>num[1];
	cout <<"3rd: ";cin>>num[2];
	int largest=num[0];
	short int i;
	for(i=1;i<3;i++){
		if(largest<num[i]){
			largest=num[i];
		}
	}
	cout <<i<<"st number is the largest ="<<largest<<"\n";
}
void reverseNumber(){
	string num;
	cout <<"Enter Number:";cin>>num;
	reverse(num.begin(),num.end());
	cout<<"Reversed numeber= "<< num;
}
int factorial(int num){
	if (num==0 || num==1){
		return 1;
	}else{
		return num*factorial(num-1);
	}
}











