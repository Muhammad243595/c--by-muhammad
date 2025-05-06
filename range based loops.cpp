#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> numbers={1,2,3,4,5};
	vector<string> names={"ali","amna","ahmad","ahad","muhammad"};
	vector<pair<int,string>> stdData={
		{1,"ali"},
		{2,"amna"},
		{3,"ahmad"},
		{4,"ahad"},
		{5,"muhammad"}
	};
	cout <<"Numbers: ";
	for(auto value:numbers){
		cout<<value<<" ";
	}
	cout <<endl;
	cout <<"Names: ";
	for(auto value:names){
		cout<<value<<" ";
	}
	cout <<endl;
	cout <<"Students data"<<endl;
	for(auto value:stdData){
		cout<<"ID: "<<value.first<<", Name: "<<value.second<<endl;
	}
	cout <<endl;
	return 0;
}