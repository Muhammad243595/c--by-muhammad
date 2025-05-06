#include<iostream>
#include<fstream>
using namespace std;
void writeData(){
	cout<<"Enter marks of three students in three diffrent subjects\n";
	string name;
	int eng,urdu,maths;
	
	cout <<"Marks Obtained in English: ";cin>>eng;
	cout <<"Marks Obtained in Urdu: ";cin>>urdu;
	cout <<"Marks Obtained in Maths: ";cin>>maths;
	ofstream write;
	write.open("student.txt");
	write<<name<<" "<<eng<<" "<<urdu<<" "<<maths<<" ";
	write.close();
}

int main(){
	writeData();
	return 0;
}