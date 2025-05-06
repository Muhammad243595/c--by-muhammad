#include<iostream>
#include<fstream>
using namespace std;
void writeData(){
	cout<<"Enter name of three students\n";
	string s1,s2,s3;
	cin>> s1>>s2>>s3;
	ofstream write;
	write.open("student.txt");
	write<<s1<<"\n"<<s2<<"\n"<<s3<<"\n";
	write.close();
}
void readData(){
	ifstream read;
	read.open("student.txt");
	string line;
	cout <<"\n---Data on file---\n";
	while(getline(read,line)){
		cout <<line<<"\n";
	}
	read.close();
}

int main(){
	writeData();
	readData();
	return 0;
}