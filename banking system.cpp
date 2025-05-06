#include<iostream>

using namespace std;

class BankAccount{
protected:	
	long long accountNumber;
	double balance;
	string accountHolderName;
	
public:
	//constructor
	BankAccount() {
    accountNumber = 0;
    balance = 0;
    accountHolderName = "Default";
	}


	bool deposit(double amount){
		if(amount>0){
			balance+=amount;
			cout <<"\n"<<amount<<"$ deposited Succecfully in "<<accountHolderName<<"'s account.\n";
			return true;
		}else{
			cout <<"\nInvalid amount!\n";
			return false;
		}
	}
	virtual bool withdraw(double amount){
		if (amount >0 && amount <balance){
			balance-=amount ;
			cout <<"\n"<<amount<<"$ withdrawed succesfully.\n";
			return true;
		}else if (amount <0){
			cout<<"\nAmount should be greater than zero\n";
			return false;
		}else if (amount >balance){
			cout<<"\nAmount is greater than the account balance\n";
			return false;
		}else{
			cout<<"\nInvalid amount\n";
			return false;
		}
	}
	double getBalance(){
		return balance;
	}
	virtual void displayAccountDetails(){
		cout <<"\n---nAccout details---\n"
			 <<"\nAccount Number: "<<accountNumber
			 <<"\nAccount Holder's Name: "<<accountHolderName
			 <<"\nAccount Balance: "<<balance<<"\n";
	}
	virtual double calculateInterest()=0;
};

class SavingAccount : public BankAccount{
private:
	double interestRate;
public:	
	SavingAccount (){
		accountNumber = 0;
	    balance = 0;
	    accountHolderName = "Default";
	    interestRate=0.0;
	}
	SavingAccount(long long accNo, string name, double bal, double rate) {
    accountNumber = accNo;
    accountHolderName = name;
    balance = bal;
    interestRate = rate;
	}

	void displayAccountDetails() override {
		cout <<"\n---Account details---\n"
			 <<"\nAccount Number: "<<accountNumber
			 <<"\nAccount Holder's Name: "<<accountHolderName
			 <<"\nAccount Balance: "<<balance
			 <<"\nInterest Rate: "<<interestRate<<"\n";
	}
	bool setInterestRate(int rate){ 
		if (rate>0){
			interestRate=rate/100;
			return true;
		}else{
			return false;
		}
		
	}
	double calculateInterest() override {
		double interest=0;
		interest =interestRate*balance;
		return interest;
	}
};

class CurrentAccount : public BankAccount{	
private:
	double overDraftLimit;
public:
	CurrentAccount (long long accNo, string name, double bal, double limit) {
    accountNumber = accNo;
    accountHolderName = name;
    balance = bal;
    overDraftLimit=limit;
	}
	bool withdraw(double amount) override {
		if (balance>overDraftLimit && amount >0){
			balance-=amount ;
			cout <<"\n"<<amount<<"$ withdrawed succesfully.\n";
			return true;
		}else if (balance<overDraftLimit){
			cout<<"\nOver Draft limit exceeded.\n";
			return false;
		}else if (amount <0){
			cout<<"\nAmount should be greater than zero\n";
			return false;
		}else{
			cout<<"\nInvalid amount\n";
			return false;
		}
	}
	void displayAccountDetails() override {
		cout <<"\n---Account details---\n"
			 <<"\nAccount Number: "<<accountNumber
			 <<"\nAccount Holder's Name: "<<accountHolderName
			 <<"\nAccount Balance: "<<balance
			 <<"\nOver Draft Limit: "<<overDraftLimit<<"\n";
	}
	double calculateInterest() override {
		cout <<"\nCurrent account does not have any interest rate.\n";
		return 0; 
	}
};

int main (){
	//demonstration
	cout <<"---------Banking System---------\n";
	CurrentAccount ac(12345, "John Doe", 1500.0, 300.5);
	ac.displayAccountDetails();
	ac.withdraw(1700);
	ac.displayAccountDetails();
	
	
	return 0;
}




