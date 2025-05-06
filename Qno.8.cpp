#include<iostream>
#include<fstream>
using namespace std;
int main (){
	ofstream read;
	read.open("roll_numbers.txt");
	int rollNo[];
	for (int i=0;;i++){
		if (getline(read,rollNo[i]));
		else return;
	}
	read.close();
}