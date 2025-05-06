#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const int days = 7;
    double temperatures[days];
    double sum = 0.0;

    
    ofstream write("temperature.txt");
    int mon,tue,wed,thur,fri,sat,sun;
	cout <<"Enter weather of seven days";
	cout <<"Monday: ";cin >>mon;
	cout <<"Tuesday: ";cin >>tue;
	cout <<"Wednesday: ";cin >>wed;
	cout <<"Thursday: ";cin >>thur;
	cout <<"Friday: ";cin >>fri;
	cout <<"Saturday: ";cin >>sat;
	cout <<"Sunday: ";cin >>sun;
    write<<mon<<endl<<tue<<endl<<wed<<endl<<thur<<endl<<fri<<endl<<sat<<endl<<sun<<endl;
    for (int i = 0; i < days; ++i) {
        inFile >> temperatures[i];
        sum += temperatures[i];
    }
    write.close();

    double average = sum / days;
    ofstream outFile("average_temp.txt");
    if (!outFile) {
        cout << "Error: Could not open average_temp.txt for writing." << endl;
        return 1;
    }
    outFile << "Weekly Average Temperature: " << average << "\n";
    outFile.close();

    cout << "Daily Temperatures and Weekly Average Saved Successfully." << endl;
    return 0;
}
