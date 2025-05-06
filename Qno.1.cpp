#include<iostream>
#include<fstream>
using namespace std;
void writeData(){
	cout<<"Enter name of three students\n";
	string s1,s2,s3;
	cin>> s1>>s2>>s3;
	ofstream write;
	write.open("student.txt");
	write<<s1<<" "<<s2<<" "<<s3<<" ";
	write.close();
}
int main(){
	writeData();
	return 0;
}