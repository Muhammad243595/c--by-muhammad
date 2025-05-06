#include<iostream>
#include<vector>
using namespace std;
int main (){
	
	vector<pair<int,string>> stdData={
	{105,"Alice"},
	{106,"Babar"},
	{107,"Cindrella"},
	{108,"Dany"},
	{109,"Elon"}
	};
	vector<pair<int,string>> ::iterator it;
	for(it=stdData.begin();it!=stdData.end();it++){
		cout <<"ID:"<< (it->first) <<", Name: "<< it->second <<endl;
	}
	while(true){
		cout <<endl<<"Enter Student id to retrieve: ";
		int x;cin >>x;
		
		if (x>104 && x<110){
				for(it=stdData.begin();it!=stdData.end();it++){
				if(it->first==x){
						cout << (it->first) <<": "<< it->second <<endl;
						
					}break;
				}
			}else{
				cout <<"\nEnter valid id !\n\n";
		}
	}
	return 0;	
}
	
	