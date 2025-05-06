#include<iostream>
#include<vector>
using namespace std;
int main (){
	vector<int> v={2,4,56,456,645,23,12,76,98,45};
	short int even=0,odd=0;
	//with rage based loop 
	for(auto value:v){
		if (value%2==0){
			even+=1;
		}else{
			odd+=1;
		}
	}
	even=0;odd=0;
	//with iterator based loop 
		for(auto it=v.begin();it!=v.end();it++){
		if (*it%2==0){
			even+=1;
		}else{
			odd+=1;
		}
	}
	
	cout<<"Even numbers= "<<even<<endl;
	cout<<"Odd numbers= "<<odd<<endl;
	return 0;
}