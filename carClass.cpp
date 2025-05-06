#include<iostream>
using namespace std;

class car{
private:
	string model;
	string brand;
	string color;
public:
	//constructor
	car(){
		cout <<"C1 executed"<<endl;
	}	
	car(string b){
		cout <<"C2 executed"<<endl;
		brand=b;
	}
	car(string m,string b, string c){
		model=m;
		brand=b;
		color=c;
		cout <<"C3 executed"<<endl;
	}	
	//setters 
	void setModel(string m){
		model=m;
	}
	void setBrand(string b){
		brand=b;
	}
	void setColor(string c){
		color=c;
	}
	
	//getters 
	string getModel(){
		return model;
	}
	string getBrand(){
		return brand;
	}
	string getColor(){
		return color;
	}
	//destrutor
	~car(){
		cout <<"I am a destructor"<<endl;
	}
};

int main(){
	int n;
	cout <<"Enter No. of cars: ";
	cin >>n;
	car showRoom[n];
	cout <<endl<<"Enter cars information"<<endl<<endl;
	
	string temp;
	for (int i=0;i<n;i++){
		cout <<"Enter brand of car " <<i+1<<": ";
		cin>>temp;
		showRoom[i].setBrand(temp);
		
		cout <<"Enter model of car " <<i+1<<": ";
		cin>>temp;
		showRoom[i].setModel(temp);
		
		cout <<"Enter color of car " <<i+1<<": ";
		cin>>temp;
		showRoom[i].setColor(temp);
		
		cout <<endl;
	}
	
	cout <<"---Cars information--- "<<endl<<endl;
	for (int i=0;i<n;i++){
		cout<<"Brand of car " <<i+1<<": "<<showRoom[i].getBrand()<<endl;
		cout<<"Model of car " <<i+1<<": "<<showRoom[i].getModel()<<endl;
		cout<<"Color of car " <<i+1<<": "<<showRoom[i].getColor()<<endl;
		
		cout <<endl;
	}
	
	return 0;
}















