#include <iostream>

using namespace std;

class BankAccount {
protected:
	int accountNo;
	double balance;
	static int accInitializer;

public:
	BankAccount() {
		accountNo = accInitializer++;
		balance = 0.0;
	}
	virtual ~BankAccount() {}

	virtual void calculateInterest() = 0;

	void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
			cout << "Deposited " << amount << ". New balance: " << balance << endl;
		} else {
			cout << "Invalid deposit amount." << endl;
		}
	}

	void withdraw(double amount) {
		if (amount > 0) {
			if (amount <= balance) {
				balance -= amount;
				cout << "Withdrew " << amount << ". New balance: " << balance << endl;
			} else {
				cout << "Insufficient funds." << endl;
			}
		} else {
			cout << "Invalid withdrawal amount." << endl;
		}
	}

	int getAccountNumber() {
		return accountNo;
	}

	void displayAccountInfo() {
		cout << "Account number is: " << accountNo << endl;
		cout << "Account balance is: " << balance << endl;
	}
};

int BankAccount::accInitializer = 1234;

class SavingsAccount : public BankAccount {
public:
	void calculateInterest() override {
		double interestRate = 0.04;
		balance += balance * interestRate;
		cout << "Interest added at 4%. New balance: " << balance << endl;
	}
};

class CheckingAccount : public BankAccount {
public:
	void calculateInterest() override {
		double interestRate = 0.01;
		balance += balance * interestRate;
		cout << "Interest added at 1%. New balance: " << balance << endl;
	}
};

class FixedDepositAccount : public BankAccount {
public:
	void calculateInterest() override {
		double interestRate = 0.06;
		balance += balance * interestRate;
		cout << "Interest added at 6%. New balance: " << balance << endl;
	}
};

class Menu {
public:
	static void displayMain() {
		cout << "\n1.Create account\n"
			 << "2.Manage account\n"
			 << "3.Exit\n\n"
			 << "Enter your choice: ";
	}

	static void displayAccountTypes() {
		cout << "\nSelect Account type\n\n"
			 << "1.SavingsAccount\n"
			 << "2.CheckingAccount\n"
			 << "3.FixedDepositAccount\n"
			 << "4.Cancel\n\n"
			 << "Enter your choice: ";
	}

	static void displayFeatures() {
		cout << "\n1.Deposit\n"
			 << "2.Withdraw\n"
			 << "3.Calculate Interest\n"
			 << "4.Back\n\n"
			 << "Enter your choice: ";
	}
};

int findIndex(BankAccount* arr[], int count, int accNo) {
	for (int i = 0; i < count; ++i) {
		if (arr[i]->getAccountNumber() == accNo)
			return i;
	}
	return -1;
}

int main() {
	BankAccount* accounts[100] = { nullptr };
	int accountCount = 0;
	string choice;

	while (true) {
		Menu::displayMain();
		getline(cin, choice);

		if (choice == "1") {
			Menu::displayAccountTypes();
			getline(cin, choice);

			BankAccount* acct = nullptr;
			if (choice == "1") {
				acct = new SavingsAccount;
			} else if (choice == "2") {
				acct = new CheckingAccount;
			} else if (choice == "3") {
				acct = new FixedDepositAccount;
			} else {
				cout << "Creation canceled." << endl;
				continue;
			}

			cout << "Enter initial deposit: ";
			getline(cin, choice);
			double amt = stod(choice);
			acct->deposit(amt);

			cout << "\nAccount created successfully. Details:\n";
			acct->displayAccountInfo();
			accounts[accountCount++] = acct;

		} else if (choice == "2") {
			if (accountCount == 0) {
				cout << "No accounts available." << endl;
				continue;
			}
			cout << "Enter account number: ";
			getline(cin, choice);
			int accNo = stoi(choice);

			int idx = findIndex(accounts, accountCount, accNo);
			if (idx < 0) {
				cout << "Account not found." << endl;
				continue;
			}

			BankAccount* acct = accounts[idx];
			cout << "\nAccount details:\n";
			acct->displayAccountInfo();

			while (true) {
				Menu::displayFeatures();
				getline(cin, choice);

				if (choice == "1") {
					cout << "Enter deposit amount: ";
					getline(cin, choice);
					double a = stod(choice);
					acct->deposit(a);
				} else if (choice == "2") {
					cout << "Enter withdrawal amount: ";
					getline(cin, choice);
					double a = stod(choice);
					acct->withdraw(a);
				} else if (choice == "3") {
					acct->calculateInterest();
				} else if (choice == "4") {
					break;
				} else {
					cout << "Invalid choice." << endl;
				}
			}

		} else if (choice == "3") {
			cout << "Thanks for using." << endl;
			break;
		} else {
			cout << "Invalid choice." << endl;
		}
	}

	// cleanup
	for (int i = 0; i < accountCount; ++i)
		delete accounts[i];

	return 0;
}
