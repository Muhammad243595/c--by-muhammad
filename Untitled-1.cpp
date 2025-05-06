#include <iostream>

int main(){
	
	std::string* s;
	s = new std::string ;
	*s="abc";
	std::cout<<*s;
	
	return 0;
}