#include<iostream>
using namespace std;

class Employee{
private:
	string EmployeeName;
	int EmployeeNumber;
	string HireDate	;
public:
	// constructor and destrutors
	Employee(){
		EmployeeName="NOT SAVED YET\n";
		EmployeeNumber=0;
		HireDate="NOT SAVED YET\n";
	}
	Employee(string EN ){
		EmployeeName=EN;
	}
	Employee(string EN,int ENO,string HD){
		EmployeeName=EN;
		EmployeeNumber=ENO;
		HireDate=HD;
	}
	//setters and getters 
	void SetEmployeeName(string s){
		EmployeeName=s;
	}
	string GetEmployeeName(){
		return EmployeeName;
	}
	bool SetEmployeeNumber(int n){
		if (n>0){
			EmployeeNumber=n;
			return true;
		}else{
			return false;
		}
		
	}
	int GetEmployeeNumber(){
		return EmployeeNumber;
	}
	void SetHireDate(string s){
		HireDate=s;
	}
	string GetHireDate(){
		return HireDate;
	}
	//main functions
	void displayEmployeeData(){
		cout <<"Name: "<<EmployeeName<<endl;
		cout <<"Employee Number: "<<EmployeeNumber<<endl;
		cout <<"Hire Date: "<<HireDate<<endl;
	}
};
class ProductionWorker :public Employee{
protected:
	int Shift;
	double HourlyPayRate;	
public:
	//constructor
	ProductionWorker(){
		Shift=0;
		HourlyPayRate=0.0;
	}	
	ProductionWorker(int n,double d){
		Shift=n;
		HourlyPayRate=d;
	}
	//setters and getters 
	bool setShift(int n){
		if (n==1||n==2){
			Shift=n;
			return true;
		}else{
			return false;
		}
	}
	int getShift(){
		return Shift;
	}
	bool setHourlyPayRate(double d){
		if (d>=0){
			HourlyPayRate=d;
			return true;
		}else{
			return false;
		}
	}
	double getHourlyPayRate(){
		return HourlyPayRate;
	}	
	//functions
	
	void displayProductionWorkerInfo(){
		displayEmployeeData();
		if (Shift==1){
			cout <<"Shift: Day\n";
		}else if (Shift==2){
			cout <<"Shift: Night\n";
		}	
		cout <<"Hourly pay rate= "<<HourlyPayRate<<endl;
	}
};

int main (){
	cout <<"----------Enter Production Worker data-------------\n\n";
	ProductionWorker w1;
	string s;double d;
	cout <<"Enter Employee name: ";cin>>s;
	w1.SetEmployeeName(s);
	
	while (true){
		cout <<"Enter Employee number: ";cin>>d;
		if (w1.SetEmployeeNumber(d)==false){
			cout <<"Invalid Entry\n";
		}
		if (w1.SetEmployeeNumber(d)==true){
			break;
		}
	}
	cout <<"Enter Hire date(dd/mm/year): ";cin>>s;
	w1.SetHireDate(s);
	while (true){
		cout <<"Enter Shift(1 or 2): ";cin>>d;
		if (w1.setShift(d)==false){
			cout <<"Invalid Entry\n";
		}
		if (w1.setShift(d)==true){
			break;
		}
	}	
		while (true){
		cout <<"Enter Hourly Pay Rate : ";cin>>d;
		if (w1.setHourlyPayRate(d)==false){
			cout <<"Invalid Entry\n";
		}
		if (w1.setHourlyPayRate(d)==true){
			break;
		}
	}
	cout <<endl<<endl;
	w1.displayProductionWorkerInfo();
	
	return 0;
}



