#include<iostream>
#include<fstream>
using namespace std;
void salesData(){
	cout <<"Enetr the number of days: ";
	int days;cin>>days;
	int sales[days-1];
	ofstream write;
	for (int i=0;i<days;i++){
		cout <<"Enter sale of day "<<i+1<<" : ";
		cin >> sales[i];
	}
	write.open("Sales.txt");
	for (int i=0;i<days;i++){
		write<<sales[i]<<endl;
	}
	cout <<"\n--Data of "<<days<<" days saved on Sales.txt--";
	write.close();
}
int main(){
	salesData();
	return 0;
}