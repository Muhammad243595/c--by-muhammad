#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> v={10,20,30,40,50};
	vector<int>::iterator it;
	cout <<"Before: ";
	for(it=v.begin();it!=v.end();it++){
		cout <<*it<<" ";
	}
	cout <<endl;
	cout <<"After: ";
	vector<int>::reverse_iterator rit;
	for(rit=v.rbegin();rit!=v.rend();rit++){
		cout <<*rit<<" ";
	}
	
	return 0;
}