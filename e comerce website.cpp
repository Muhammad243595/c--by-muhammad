#include<iostream>
#include<fstream>
using namespace std;

void displayMenu(){
	cout <<"1.Login\n2.Sign up\n\n";	
	cout <<"Enter your choice: ";
}
bool inputValidator(){
}
void Ii(){
	cout <<"Please Enter a valid option!\n\n";
}
int main(){
	char option[];
	cout <<"--------Welcome to the console based version of an E-comerce website--------\n\n";
	do {
		displayMenu();
		cin>>option;
		if (option==1||option==2){
			break;
		}else{
			Ii();
		}
	
	}while(true);
	
	return 0;
	
}