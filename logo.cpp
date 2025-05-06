#include <iostream>
using namespace std;

int findSecondLargest(int arr[], int n) {  // ERROR: Wrong function brackets
    if (n < 2)  // ERROR: Missing parentheses ()
        cout << "Error";  // ERROR: Returning string in an int function

    int largest, secondLargest;
    largest == secondLargest == arr[0];  // ERROR: Wrong assignment

    for (int i = 1; i < n; i++) {  // ERROR: Wrong syntax for loop
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];  // ERROR: Missing semicolon
        }
        else if (arr[i] > secondLargest && arr[i] != largest)
            secondLargest = arr[i];   

    return secondLargest;
}
return 0;
}
int main() {
    int n;
    cout << "Enter size of array:";
    cin >> n;
    
    int arr[n];  // ERROR: Wrong array declaration
    cout << "Enter "<< n <<" elements:" << endl;  // ERROR: Wrong string concatenation
    for (int i = 0; i < n; i++)  
        cin >> arr[i];  // ERROR: Missing semicolon

    int result = findSecondLargest(arr, n);
    cout << "Second largest element is: "<< result << endl;  // ERROR: Wrong output syntax

    return 0;
}
