#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
void saveData(){
	cout <<"Enter First name of 10 students. \n";
	string stdData[10];
	for (int i=0;i<10;i++){
		cout <<"Enter name of studen "<<i+1<<" : ";
		cin >>stdData[i];
	}
	ofstream write;
	write.open("students.txt");
	for (int i=0;i<10;i++){
		write<<stdData[i]<<endl;
	}
	cout <<"Data succeccfuly written on a file";
	write.close();
}
void displayData(){
	cout <<"\nDo you want to display data from students.txt (yes/no):";
	string choice;cin>>choice;
	if (choice=="yes" or choice =="YES" or choice=="Yes"){
		ifstream read;
		read.open("students.txt");
		string line;
		cout <<"--Students list--\n";
		int i=1;
		while (getline(read,line)){
			cout <<"Student "<<i<<": "<<line<<endl;
			i++;}
	}else if (choice=="No" or choice =="no" or choice=="NO"){
		cout<<"Thanks for using";
	}else {
		cout <<"\nInvalid choice, try again.";
	}
}
int main (){
	saveData();
	displayData();
	return 0;
}