#include<iostream>
using namespace std ;

struct Employee{
private:	
	string employeeName;
	int ID;
	double salary;
public:
	//constructors
	Employee(){
		employeeName="None";
		ID=0;
		salary =0.0;
	}
	Employee(string n,int i,double s){
		employeeName=n;
		ID=i;
		salary =s;
	}
//declarations of setters and getters 

	void setName(string);
	string getName();
	
	void setID(int);
	int getID();
	
	void setSalary(double);
	double getsalary();
//other methods
	void annualSalaryRaise(double);
	
};
void displayMenu();

int main (){
	cout <<"-----Aslamualykumn-----\n";
	short int n ;
	do {
		cout <<"How many Employees you want to create: ";
		cin >>n;
		if (n>0){
		break;
		}else{
			cout <<"Invalid Entry. Try again.\n";
		}
	}while(true);
	
	cout <<n<<" employees created \n";
	//for creating the exact number of employees enterd by the users
	Employee *emp[n];
	for(short int i=0;i<n;i++){
		emp[i]=new Employee;
	}
	short int empNo;
	do {
		cout<<"Enter employee Number (1 to "<<n<< ") for setting and accessing data: ";
		cin >>empNo;
		if (empNo>0){
			empNo--;
			break;
		}else{
			cout <<"Invalid Entry. Try again.\n";
		}
	}while(true);
	
	
	

	cout <<"\nWhat do you want to do?\n";
	do{
		displayMenu();
		short int *choice ;
		choice=new short int ;
		cout<<"Enter your choice: ";
	cin >>*choice;	
	if (*choice==1){
		string name;
		cout <<"Enter name of Employee: ";cin >>name;
		emp[empNo]->setName(name);
		cout <<"Name Successfully set\n";
	}
	else if (*choice==2){
		int ID;
		cout <<"Enter ID for Employee: ";cin >>ID;
		emp[empNo]->setID(ID);
		cout <<"Employee ID Successfully set\n";
	}
	else if (*choice==3){
		double sal;
		cout <<"Enter salary of Employee: ";cin >>sal;
		emp[empNo]->setSalary(sal);
		cout <<"Employee salary Successfully set\n";
	}
	else if (*choice==4){
	cout <<endl <<"Name: "<<emp[empNo]->getName()<<endl;
	cout <<"Id: "<<emp[empNo]->getID()<<endl;
	cout <<"Salary: "<<emp[empNo]->getsalary()<<endl<<endl;	
	}
	else if (*choice==5){
		cout <<"Enter employee number: ";
		cin >>empNo;
	}
	else if (*choice==6){
		cout <<"Enter Employee number you want to delete: ";
		cin>>empNo;
		delete emp[empNo];
	}
	else if (*choice==7){
		cout <<"Do you want to delete all Emplyees(yes or no)";string *s=new string;
		cin >>*s;
		if(*s=="yes"||*s=="y"||*s=="YES"||*s=="Yes"){
			for (short int i=0;i<n;i++){
				delete emp[i];
			}
			cout <<"All employees deleted\n";
		}
	}
	else if (*choice==8){
		cout <<"Closing the program....\n";
		exit(1);
	}
	else{
		cout <<"Invalid Option\n";
		break;
	}	
	//deleting pointerts 
	delete choice;choice=0;
}while(true);

	return 0;
}

//function definitions
void Employee::setName(string s) {
	employeeName =s;
}
string Employee::getName(){
	return employeeName;
}

void Employee::setID(int i){
	ID=i;
}
int Employee::getID(){
	return ID;
}

void Employee::setSalary(double s){
	if (s>0){
		salary=s;
	}
}
double Employee::getsalary(){
	return salary;
}
void Employee::annualSalaryRaise(double percentage){
	if (percentage>0){
		salary +=(percentage*salary);
	}else{
		cout <<"Enter a valid percentage.\n";
	}
}
void displayMenu(){
	cout<<"\n1.Set name. \n";
	cout<<"2.Set ID.\n";
	cout<<"3.Set Salary.\n";
	cout<<"4.Get Employee Info.\n";
	cout<<"5.Select another Employee.\n";
	cout<<"6.Delete Employee.\n";
	cout<<"7.Delete All Employees";
	cout<<"8.Exit.\n";
}