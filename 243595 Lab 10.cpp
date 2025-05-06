#include<iostream>

using namespace std;

class Point{
	float real;
	float imag;
public:
	Point(){}
	Point(float x,float y){
		real=x;
		imag=y;
		
	}
		
	void diplay(){
		cout <<"Real: "<<real<<"\nImaginary: "<<imag<<"\n";
	}
	
	float getReal(){
		return real;
	}
	
	float getImaginary(){
		return real;
	}
	bool operator==(Point& other){
		if (other.getReal()==real && other.getImaginary()== imag){
			return true;
		}else
			return false;
	}

	Point operator+(Point& other){
		Point temp;
		temp.real=real+other.real;
		
		temp.imag=imag+other.imag;
		
		return temp;
	}
	
	Point operator-(Point& other){
		Point temp;
		temp.real=real-other.real;
		temp.imag=imag-other.imag;
		
		return temp;
	}

	Point operator/(Point& other){
			Point temp;
			temp.real=real/other.real;
			temp.imag=imag/other.imag;
			
			return temp;
		}

	Point operator*(Point& other){
		Point temp;
		temp.real=real*other.real;
		temp.imag=imag*other.imag;
		
		return temp;
	}


};

int main (){
	Point p1(2,3),p2(4,5);
	cout <<"---Point 1---\n";	
	p1.diplay();
	cout <<"\n---Point 2---\n";
	p2.diplay();
	
	
	
	cout <<"\n---Equality Check---\n\n";
	if(p1==p2){
		cout <<"Both points are Equal\n";
	}else 
		cout <<"Points are not Equal\n";
	
	Point result;
	cout <<"\n---Sum---\n\n";
	result=p1+p2;
	
	result.diplay();
	cout <<"\n---Difference---\n\n";
	result=p1-p2;
	result.diplay();
	
	cout <<"\n---Division---\n\n";
	result=p1/p2;
	result.diplay();
	
	cout <<"\n---Multiplication---\n\n";
	result=p1*p2;
	result.diplay();
	
	return 0;
}