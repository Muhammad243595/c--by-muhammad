#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
void caculateSumOfMarks(){
	ifstream read;
	string name,line;
	int total;
	read.open("student.txt");
	
	read.close();

	cout <<"Name: "<<name;
	cout <<"Total Marks Obtained: "<<total;
	
	
}

int main(){
	caculateSumOfMarks();
	return 0;
}