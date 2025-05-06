#include<iostream>
using namespace std;

int largest (int ar[],int s){
	int max=ar[0];
	for (int i=0;i<s;i++){
		if (ar[i]>max){
			max=ar[i];
		}
	}return max;
} 
void multiplyArray(int *ar,int s,int n){
	for(int i=0;i<s;i++){
		ar[i]=ar[i]*n;
	}
} 
int calculateSum(int ar[],int s){
	int sum=0;
	for(int i=0;i<s;i++){
		sum+=ar[i];
	}
	return sum;
}

void reverseArray(int ar[],int s){
	
	while (ar[0]!=ar[s-1]){
		swap(ar[0],ar[s-1]);
		ar[0]++;
		ar[s-1]++;
	}
}

int main(){
	int s=5;
    int a [s]={10, 20, 30, 40, 50};
    reverseArray(a,s);
    for(int i=0;i<s;i++){
		cout <<a[i]<<" ";
	}
    
    
}