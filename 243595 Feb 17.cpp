#include<iostream>
using namespace std;
class BankAccount{
	private:
		//account holder information
		string name;
		long int accountNo;
		int number;
		int balance=0;
		long int accountInitializer=1987654321;
		
	public:
	BankAccount(){
			accountNo=accountInitializer;
			accountInitializer+=1;
		}
		//setters
		void setName(){
			cin>>name;
		}
		void depositMoney(){
			long int x;
			cin >>x;
			if (x>0){
				balance+x;
				cout <<x<<" deposited successfuly in "<<accountNo<<" owned by "<<name;
			}else{
				cout<<"Invalid Entry\nEnter agian: ";
				depositMoney();
			}
			
		}
		void setNumber(){
			long int x;
			cin >>x;
			number=x;
		}
		//getter
		void withDrawMoney(){
			long int x;
			cin >>x;
			if (x>0){
				if(balance>x && balance>0){
				balance=balance-x;
			}else{
				cout <<"Insufficient balance.\n";}
				
				}else {
				cout <<"Enter a valid value.\n";
				withDrawMoney();
			}
		}
		long int getBalance(){
			return balance;
		}
};
int main (){
	BankAccount emp1;
	
	cout <<"---Create an account--- \n\n";
	cout <<"Enter credentials of the 1st account\n\n";
	cout <<"Enter Name: ";emp1.setName();
	cout <<"Enter Phone Number: ";emp1.setNumber();
	cout <<"Deposit Money: ";emp1.depositMoney();
	
	return 0;
}