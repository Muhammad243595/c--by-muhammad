#include <iostream>
#include <fstream>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

int main() {
    json data;

    ifstream read("data.json");
    if (!read.is_open()) {
        cerr << "Error: Could not open data.json" << endl;
        return 1;
    }

    try {
        read >> data;
    } catch (json::parse_error& e) {
        cerr << "Error: Failed to parse JSON - " << e.what() << endl;
        return 1;
    }

    if (data.contains("data_types")) {
        
            cout << it.key() << ": " << it.value() << endl << endl;
        
    } else {
        cerr << "Error: JSON does not contain 'data_types'" << endl;
        return 1;
    }

    return 0;
}