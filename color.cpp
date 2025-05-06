#include <iostream>
#include <windows.h>

void setRedTextColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void resetTextColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int main() {
    setRedTextColor();  // Set red color for error message
    std::cout << "Error: Something went wrong!\n";

    resetTextColor();   // Reset back to default color
    std::cout << "This is a normal message.\n";

    return 0;
}
