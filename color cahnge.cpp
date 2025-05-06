#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

void setConsoleColor(char bg, char fg) {
    std::string cmd = "color ";
    cmd += bg;
    cmd += fg;
    system(cmd.c_str());
}

void showAllCombinations() {
    const char* hex = "0123456789ABCDEF";

    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            if (i == j) continue; // skip same bg/fg (invisible)

            setConsoleColor(hex[i], hex[j]);

            std::cout << "Background: " << hex[i]
                      << ", Text: " << hex[j]
                      << " (color " << hex[i] << hex[j] << ")\n";

            std::this_thread::sleep_for(std::chrono::milliseconds(150));
        }
    }

    // Reset to default (black bg, light gray text)
    setConsoleColor('0', '7');
}

int main() {
    showAllCombinations();
    return 0;
}
