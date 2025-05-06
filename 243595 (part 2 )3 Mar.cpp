#include<iostream>
using namespace std;

class Rectangle{
private: 
	double length;
	double width;
public:
	//constructors
	Rectangle(){
		length=0.0;
		width=0.0;
	}
	Rectangle(double l,double w){
		length=l;
		width=w;
	}	
	//destructor
	~Rectangle(){
		cout <<"Objects of class 'Rectangle' are destroyed\n";
	}
	//setters and getters
	void setWidth(double x){
		if (x>=0){
			width=x;
		}else{
			cout <<"Invalid Width\n";
		}
	}
	double getWidth(){
		return width;
	}
	
	void setLength(double y){
		if (y>=0){
			length=y;
		}else{
			cout <<"Invalid length\n";
		}
		
	}	
	double getLength(){
		return length;
	}
	//methods
	double calculateArae(){
		return (length*width);
	}
	double calculatePerimeter(){
		return (2*length+2*width);
	}
};
void displayMenu(){
	cout <<"1.Calculate Area\n";
	cout <<"2.Calculate permiter\n";
	cout <<"3.Exit.\n";
}
int main (){
	int n=1;
	Rectangle *obj[n];
	obj[1]=new Rectangle;
	do {
		cout <<"Enter width of rectangle: ";
		double s;cin>>s;obj[1]->setWidth(s);
		cout <<"Enter length of rectangle: ";
		cin>>s;obj[1]->setLength(s);
		displayMenu();
		short int choice;cin >>choice;
	if (choice==1){
		cout <<"Area: "<<obj[1]->calculateArae()<<endl;
	}else if (choice==2){
		cout <<"Perimiter: "<<obj[1]->calculateArae()<<endl;
	}
	else {
		break;
		
	}	
}while(true);
	delete obj[1];
	return 0;
}