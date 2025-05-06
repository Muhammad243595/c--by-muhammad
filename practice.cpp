#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main() {
    string input;
    getline(cin, input); // Read entire line

    stringstream ss(input);
    int intValue;
    double doubleValue;

    if (ss >> intValue) {
        if (ss.eof()) { // Ensure no trailing characters
            cout << "Input is an integer: " << intValue << endl;
        } else {
            cout << "Input has trailing characters after integer.\n";
        }

    } else {
        ss.clear(); // Clear error flags
        ss.str(input); // Reset stringstream

        if (ss >> doubleValue) {
            if (ss.eof()) {
                cout << "Input is a double: " << doubleValue <<endl;
            } else {
                cout << "Input has trailing characters after double.\n";
            }
        } else {
            cout << "Input is a string: " << input <<endl;
        }
    }

    return 0;
}