#include <iostream>
#include <windows.h>
#include <string>

class Color {
public:
    static void setRedTextColor() {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    }

    static void resetTextColor() {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    static void setGreenTextColor() {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    }

    static void setBlueTextColor() {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }


};

class Driver {
    private:
        std::string name;
        std::string phoneNumber;
        int age;
    public:
        Driver() {
            name = "\0";
            phoneNumber = "\0";
            age = 0;
        }

        // Setters with validation
        bool setName(const std::string& driverName) {
            if (driverName.empty()) {
                Color::setRedTextColor();
                std::cout << "Error: Name cannot be empty.\n\n";
                Color::resetTextColor();
                return false;
            }

            for (char ch : driverName) {
                if (ch == ' ') {
                    Color::setRedTextColor();
                    std::cout << "Error: Name must not contain spaces.\n\n";
                    Color::resetTextColor();
                    return false;
                }
                if (isdigit(ch)) {
                    Color::setRedTextColor();
                    std::cout << "Error: Name must not contain numbers.\n\n";
                    Color::resetTextColor();
                    return false;
                }
                if (!isalpha(ch)) {
                    Color::setRedTextColor();
                    std::cout << "Error: Name must not contain special characters.\n\n";
                    Color::resetTextColor();
                    return false;
                }
            }

            name = driverName;
            return true;
        }

        bool setPhoneNumber(const std::string& driverNumber) {
            if (driverNumber.empty()) {
                Color::setRedTextColor();
                std::cout << "Error: Phone Number cannot be empty.\n\n";
                Color::resetTextColor();
                return false;
            }

            
            for (char ch : driverNumber) {
                if (ch == ' ') {
                    Color::setRedTextColor();
                    std::cout << "Error: Phone Number must not contain spaces.\n\n";
                    Color::resetTextColor();
                    return false;
                }
                if (isalpha(ch)) {
                    Color::setRedTextColor();
                    std::cout << "Error: Phone Number must not contain alphabets.\n\n";
                    Color::resetTextColor();
                    return false;
                }
                if (!isdigit(ch)) {
                    Color::setRedTextColor();
                    std::cout << "Error: Phone Number must not contain special characters.\n\n";
                    Color::resetTextColor();
                    return false;
                }
            }

            if (driverNumber.length() != 11) {
                Color::setRedTextColor();
                std::cout << "Error: Phone Number must contain 11 digits.\n\n";
                Color::resetTextColor();
                return false;
            }

            phoneNumber = driverNumber;
            return true;
        }

        bool setAge(const std::string& driverAge) {
            if (driverAge.empty()) {
                Color::setRedTextColor();
                std::cout << "Error: Age cannot be empty.\n\n";
                Color::resetTextColor();
                return false;
            }

            for (char ch : driverAge) {
                if (ch == ' ') {
                    Color::setRedTextColor();
                    std::cout << "Error: Age must not contain spaces.\n\n";
                    Color::resetTextColor();
                    return false;
                }
                if (isalpha(ch)) {
                    Color::setRedTextColor();
                    std::cout << "Error: Age must not contain alphabets.\n\n";
                    Color::resetTextColor();
                    return false;
                }
                if (!isdigit(ch)) {
                    Color::setRedTextColor();
                    std::cout << "Error: Age must not contain special characters.\n\n";
                    Color::resetTextColor();
                    return false;
                }
            }

            age = std::stoi(driverAge);
            if (age < 18 || age > 75) {
                Color::setRedTextColor();
                std::cout << "Error: Age must be between 18 and 75.\n\n";
                Color::resetTextColor();
                return false;
            }
            return true;
        }


        // Getters
        std::string getName() const {
            return name;
        }

        std::string getPhoneNumber() const {
            return phoneNumber;
        }

        int getAge() const {
            return age;
        }

};

class Schedule {
    private:
        std::string departureTime;
        std::string departureCity;
        std::string arrivalTime;
        std::string arrivalCity;
    public:
        Schedule() {
            departureTime = "\0";
            departureCity = "\0";
            arrivalTime = "\0";
            arrivalCity = "\0";
        }
        //Setter for Departure Time
        bool setDepartureTime(const std::string& time) {
            if (time.empty()) {
                Color::setRedTextColor();
                std::cout << "Error: Time must not be empty.\n\n";
                Color::resetTextColor();
                return false;
            }
            for (char ch : time) {
                if (ch == ' ') {
                    Color::setRedTextColor();
                    std::cout << "Error: Time must not contain spaces.\n\n";
                    Color::resetTextColor();
                    return false;
                }
            }
            if (time.length() != 5 || time[2] != ':') {
                Color::setRedTextColor();
                std::cout << "Error: Time must be in HH:MM (24-hour format).\n\n";
                Color::resetTextColor();
                return false;
            }

            std::string hoursStr = time.substr(0, 2);
            std::string minutesStr = time.substr(3, 2);

            if (!isdigit(hoursStr[0]) || !isdigit(hoursStr[1]) ||
                !isdigit(minutesStr[0]) || !isdigit(minutesStr[1])) {
                Color::setRedTextColor();
                std::cout << "Error: Time must only contain numeric values.\n\n";
                Color::resetTextColor();
                return false;
            }

            int hours = std::stoi(hoursStr);
            int minutes = std::stoi(minutesStr);

            if (hours < 0 || hours > 23) {
                Color::setRedTextColor();
                std::cout << "Error: Hours must be between 00 and 23.\n\n";
                Color::resetTextColor();
                return false;
            }

            if (minutes < 0 || minutes > 59) {
                Color::setRedTextColor();
                std::cout << "Error: Minutes must be between 00 and 59.\n\n";
                Color::resetTextColor();
                return false;
            }

            departureTime = time;
            return true;
        }

        // Setter for Departure City
        bool setDepartureCity(const std::string& city) {
            if (city.empty()) {
                Color::setRedTextColor();
                std::cout << "Error: Departure city cannot be empty.\n\n";
                Color::resetTextColor();
                return false;
            }

            for (char ch : city) {
                if (ch == ' ') {
                    Color::setRedTextColor();
                    std::cout << "Error: Departure city must not contain spaces.\n\n";
                    Color::resetTextColor();
                    return false;
                }
                if (isdigit(ch)) {
                    Color::setRedTextColor();
                    std::cout << "Error: Departure city must not contain digits.\n\n";
                    Color::resetTextColor();
                    return false;
                }
                if (!isalpha(ch)) {
                    Color::setRedTextColor();
                    std::cout << "Error: Departure city must not contain special characters.\n\n";
                    Color::resetTextColor();
                    return false;
                }
            }

            departureCity = city;
            return true;
        }

        // Setter for Arrival Time (Same validation as Departure Time)
        bool setArrivalTime(const std::string& time) {
            for (char ch : time) {
                if (ch == ' ') {
                    Color::setRedTextColor();
                    std::cout << "Error: Time must not contain spaces.\n\n";
                    Color::resetTextColor();
                    return false;
                }
            }

            if (time.length() != 5 || time[2] != ':') {
                Color::setRedTextColor();
                std::cout << "Error: Time must be in HH:MM (24-hour format).\n\n";
                Color::resetTextColor();
                return false;
            }

            std::string hoursStr = time.substr(0, 2);
            std::string minutesStr = time.substr(3, 2);

            if (!isdigit(hoursStr[0]) || !isdigit(hoursStr[1]) ||
                !isdigit(minutesStr[0]) || !isdigit(minutesStr[1])) {
                Color::setRedTextColor();
                std::cout << "Error: Time must only contain numeric values.\n\n";
                Color::resetTextColor();
                return false;
            }

            int hours = std::stoi(hoursStr);
            int minutes = std::stoi(minutesStr);

            if (hours < 0 || hours > 23) {
                Color::setRedTextColor();
                std::cout << "Error: Hours must be between 00 and 23.\n\n";
                Color::resetTextColor();
                return false;
            }

            if (minutes < 0 || minutes > 59) {
                Color::setRedTextColor();
                std::cout << "Error: Minutes must be between 00 and 59.\n\n";
                Color::resetTextColor();
                return false;
            }

            arrivalTime = time;
            return true;
        }

        // Setter for Arrival City
        bool setArrivalCity(const std::string& city) {
            if (city.empty()) {
                Color::setRedTextColor();
                std::cout << "Error: Arrival city cannot be empty.\n\n";
                Color::resetTextColor();
                return false;
            }

            for (char ch : city) {
                if (ch == ' ') {
                    Color::setRedTextColor();
                    std::cout << "Error: Arrival city must not contain spaces.\n\n";
                    Color::resetTextColor();
                    return false;
                }
                if (isdigit(ch)) {
                    Color::setRedTextColor();
                    std::cout << "Error: Arrival city must not contain digits.\n\n";
                    Color::resetTextColor();
                    return false;
                }
                if (!isalpha(ch)) {
                    Color::setRedTextColor();
                    std::cout << "Error: Arrival city must not contain special characters.\n\n";
                    Color::resetTextColor();
                    return false;
                }
            }

            arrivalCity = city;
            return true;
        }

        // Getters
        std::string getDepartureTime() const {
            return departureTime;
        }

        std::string getDepartureCity() const {
            return departureCity;
        }

        std::string getArrivalTime() const {
            return arrivalTime;
        }

        std::string getArrivalCity() const {
            return arrivalCity;
        }

};

class Bus {
    private:
        int busID;
        std::string numberPlate;
        int totalSeats;
        bool *availableSeats; //True for Available, False for Booked
        std::string type;
        float fare;
        Driver d;
        Schedule s;
    public:
        Bus() {
            busID = 0;
            numberPlate = "NULL";
            totalSeats = 0;
            availableSeats = nullptr;
            type = "NULL";
            fare = 0.0;
        }
        
        ~Bus() {
            delete []availableSeats;
        }

        //Setters
        void setAvailableSeats(const int seats) {
            availableSeats = new bool[totalSeats];
            for (int i = 0; i < totalSeats; i++) {
                availableSeats[i] = true;
            }
            return;
        }
        
        bool setTotalSeats(const std::string& seats) {
            if (seats.empty()) {
                Color::setRedTextColor();
                std::cout << "Error: Seats must not contain spaces.\n\n";
                Color::resetTextColor();
                return false;
            }
            for (const char ch : seats) {
                if (ch == ' ') {
                    Color::setRedTextColor();
                    std::cout << "Error: Seats must not contain spaces.\n\n";
                    Color::resetTextColor();
                    return false;
                }
                if (isalpha(ch)) {
                    Color::setRedTextColor();
                    std::cout << "Error: Seats must not contain alphabets.\n\n";
                    Color::resetTextColor();
                    return false;
                }
                if (!isdigit(ch)) {
                    Color::setRedTextColor();
                    std::cout << "Error: Seats must not contain special characters.\n\n";
                    Color::resetTextColor();
                    return false;
                }
            }

            totalSeats = std::stoi(seats);
            if (totalSeats < 1 || totalSeats > 150) {
                Color::setRedTextColor();
                std::cout << "Error: Seats must be in between 1 and 150.\n\n";
                Color::resetTextColor();
                return false;
            }
            setAvailableSeats(totalSeats);
            return true;
        }
        
        bool setBusID(const std::string& id) {
            if (id.empty()) {
                Color::setRedTextColor();
                std::cout << "Error: Bus ID can not be empty.\n\n";
                Color::resetTextColor();
                return false;
            }
            for (const char ch : id) {
                if (ch == ' ') {
                    Color::setRedTextColor();
                    std::cout << "Error: Bus ID must not contain spaces.\n\n";
                    Color::resetTextColor();
                    return false;
                }
                if (isalpha(ch)) {
                    Color::setRedTextColor();
                    std::cout << "Error: Bus ID must not contain alphabets.\n\n";
                    Color::resetTextColor();
                    return false;
                }
                if (!isdigit(ch)) {
                    Color::setRedTextColor();
                    std::cout << "Error: Bus ID must not contain special characters.\n\n";
                    Color::resetTextColor();
                    return false;
                }
                
            }

            busID = std::stoi(id);
            if (busID < 1 || busID > 9999) {
                Color::setRedTextColor();
                std::cout << "Error: Bus ID must be in between 1 and 9999.\n\n";
                Color::resetTextColor();
                return false;
            }
            return true;
        }

        bool setNumberPlate(const std::string& plate) {
            if (plate.empty()) {
                Color::setRedTextColor();
                std::cout << "Error: Number Plate can not be empty.\n\n";
                Color::resetTextColor();
                return false;
            }
            if (plate.length() != 6) {
                Color::setRedTextColor();
                std::cout << "Error: Number Plate must be exactly of 6 characters.\n\n";
                Color::resetTextColor();
                return false;
            }
            if (!isalpha(plate[0]) || !isalpha(plate[1]) || !isalpha(plate[2]) || 
                !isdigit(plate[3]) || !isdigit(plate[4]) || !isdigit(plate[5])) {
                Color::setRedTextColor();
                std::cout << "Error: Number Plate must match the format AAA000.\n\n";
                Color::resetTextColor();
                return false;
            }
            numberPlate = plate;
            return true;
        }
        
        bool setType(const std::string& busType) {
            if (busType.empty()) {
                Color::setRedTextColor();
                std::cout << "Error: Bus Type can not be empty.\n\n";
                Color::resetTextColor();
                return false;
            }
            for (const char ch : busType) {
                if (ch == ' ') {
                    Color::setRedTextColor();
                    std::cout << "Error: Bus Type must not contain spaces.\n\n";
                    Color::resetTextColor();
                    return false;
                }
                if (isdigit(ch)) {
                    Color::setRedTextColor();
                    std::cout << "Error: Bus Type must not contain digits.\n\n";
                    Color::resetTextColor();
                    return false;
                }
                if (!isalpha(ch)) {
                    Color::setRedTextColor();
                    std::cout << "Error: Bus Type must not contain special characters.\n\n";
                    Color::resetTextColor();
                    return false;
                }
            }
            std::string validTypes[] = { "Economy", "Business", "Executive", "Sleeper", "VIP" };
            for (const std::string& typeOption : validTypes) {
                if (busType == typeOption) {
                    type = busType;
                    return true;
                }
            }
            Color::setRedTextColor();
            std::cout << "Error: Invalid bus type. Choose from: Economy, Business, Executive, Sleeper, VIP.\n\n";
            Color::resetTextColor();
            return false;
        }

        bool setFare(const std::string& price) {
            if (price.empty()) {
                Color::setRedTextColor();
                std::cout << "Error: Fare can not be empty.\n\n";
                Color::resetTextColor();
                return false;
            }
            if (price[0] == '.' || price[price.length() - 1] == '.') {
                Color::setRedTextColor();
                std::cout << "Error: Fare must match the 0.00 format.\n\n";
                Color::resetTextColor();
                return false;
            }
            for (const char ch : price) {
                if (ch == ' ') {
                    Color::setRedTextColor();
                    std::cout << "Error: Fare must not contain spaces.\n\n";
                    Color::resetTextColor();
                    return false;
                }
                if (isalpha(ch)) {
                    Color::setRedTextColor();
                    std::cout << "Error: Fare must not contain alphabets.\n\n";
                    Color::resetTextColor();
                    return false;
                }
                if (!isdigit(ch) && ch != '.') {
                    Color::setRedTextColor();
                    std::cout << "Error: Fare must not contain special characters except . character.\n\n";
                    Color::resetTextColor();
                    return false;
                }
            }
            fare = std::stof(price);
            if (fare < 1.0 || fare > 999.0) {
                Color::setRedTextColor();
                std::cout << "Error: Fare amount must be in between 1 and 999.\n\n";
                Color::resetTextColor();
                return false;
            }
            return true;
        }

        //Driver Setters
        bool setDriverName(const std::string& name) {
            if (d.setName(name)) {
                return true;
            }
            return false;
        }

        bool setDriverNumber(const std::string& number) {
            if (d.setPhoneNumber(number)) {
                return true;
            }
            return false;
        }

        bool setDriverAge(const std::string& age) {
            if (d.setAge(age)) {
                return true;
            }
            return false;
        }

        //Schedule Setters
        bool setDepartureCity(const std::string city) {
            if (s.setDepartureCity(city)) {
                return true;
            }
            return false;
        }

        bool setDepartureTime(const std::string time) {
            if (s.setDepartureTime(time)) {
                return true;
            }
            return false;
        }

        bool setArrivalCity(const std::string city) {
            if (s.setArrivalCity(city)) {
                return true;
            }
            return false;
        }

        bool setArrivalTime(const std::string time) {
            if (s.setArrivalTime(time)) {
                return true;
            }
            return false;
        }

        //Getters
        bool getAvailableSeats(const int seatNo) const  {
            if (seatNo < 0 || seatNo >= totalSeats) {
                Color::setRedTextColor();
                std::cout << "Error: Invalid Seat Number, assuming seat is booked.\n\n";
                Color::resetTextColor();
                return false;
            }
            return availableSeats[seatNo];
        }

        int getTotalSeats() const  {
            return totalSeats;
        }

        int getBusID() const  {
            return busID;
        }

        std::string getNumberPlate() const {
            return numberPlate;
        }

        std::string getBusType() const  {
            return type;
        }

        float getFare() const  {
            return fare;
        }

        //Driver Getters
        int getDriverAge() const  {
            return d.getAge();
        }

        std::string getDriverName() const  {
            return d.getName();
        }

        std::string getDriverNumber() const  {
            return d.getPhoneNumber();
        }

        //Schedule Getters
        std::string getDepartureCity() const {
            return s.getDepartureCity();
        }

        std::string getDepartureTime() const {
            return s.getDepartureTime();
        }

        std::string getArrivalCity() const {
            return s.getArrivalCity();
        }

        std::string getArrivalTime() const {
            return s.getArrivalTime();
        }
};

class BusDetailsInput {
    private:
        std::string input;
        Bus b;
    public:
        BusDetailsInput() {
            input = "\0";
        }

        void inputBusID() {
            while (true) {
                std::cout << "Enter Bus ID: ";
                getline(std::cin, input);
                if (b.setBusID(input)) {
                    Color::setGreenTextColor();
                    std::cout << "Saved.\n\n";
                    Color::resetTextColor();
                    break;
                }
            }
        }

        void inputBusNumberPlate() {
            while (true) {
                std::cout << "Enter Bus Number Plate: ";
                getline(std::cin, input);
                if (b.setNumberPlate(input)) {
                    Color::setGreenTextColor();
                    std::cout << "Saved.\n\n";
                    Color::resetTextColor();
                    break;
                }
            }
        }

        void inputBusTotalSeats() {
            while (true) {
                std::cout << "Enter Bus Total Seats: ";
                getline(std::cin, input);
                if (b.setTotalSeats(input)) {
                    Color::setGreenTextColor();
                    std::cout << "Saved.\n\n";
                    Color::resetTextColor();
                    break;
                }
            }
        }

        void inputBusType() {
            while (true) {
                std::cout << "Enter Bus Type: ";
                getline(std::cin, input);
                if (b.setType(input)) {
                    Color::setGreenTextColor();
                    std::cout << "Saved.\n\n";
                    Color::resetTextColor();
                    break;
                }
            }
        }

        void inputBusFare() {
            while (true) {
                std::cout << "Enter Bus Fare: ";
                getline(std::cin, input);
                if (b.setFare(input)) {
                    Color::setGreenTextColor();
                    std::cout << "Saved.\n\n";
                    Color::resetTextColor();
                    break;
                }
            }
        }
        //Bus Driver
        void inputBusDriverName() {
            while (true) {
                std::cout << "Enter Bus Driver's Name: ";
                getline(std::cin, input);
                if (b.setDriverName(input)) {
                    Color::setGreenTextColor();
                    std::cout << "Saved.\n\n";
                    Color::resetTextColor();
                    break;
                }
            }
        }

        void inputBusDriverNumber() {
            while (true) {
                std::cout << "Enter Bus Driver's Phone Number: ";
                getline(std::cin, input);
                if (b.setDriverNumber(input)) {
                    Color::setGreenTextColor();
                    std::cout << "Saved.\n\n";
                    Color::resetTextColor();
                    break;
                }
            }
        }

        void inputBusDriverAge() {
            while (true) {
                std::cout << "Enter Bus Driver's Age: ";
                getline(std::cin, input);
                if (b.setDriverAge(input)) {
                    Color::setGreenTextColor();
                    std::cout << "Saved.\n\n";
                    Color::resetTextColor();
                    break;
                }
            }
        }

        void inputBusDepartureCity() {
            while (true) {
                std::cout << "Enter Bus's Departure City: ";
                getline(std::cin, input);
                if (b.setDepartureCity(input)) {
                    Color::setGreenTextColor();
                    std::cout << "Saved.\n\n";
                    Color::resetTextColor();
                    break;
                }
            }
        }

        void inputBusDepartureTime() {
            while (true) {
                std::cout << "Enter Bus's Departure Time: ";
                getline(std::cin, input);
                if (b.setDepartureTime(input)) {
                    Color::setGreenTextColor();
                    std::cout << "Saved.\n\n";
                    Color::resetTextColor();
                    break;
                }
            }
        }

        void inputBusArrivalCity() {
            while (true) {
                std::cout << "Enter Bus's Arrival City: ";
                getline(std::cin, input);
                if (b.setArrivalCity(input)) {
                    Color::setGreenTextColor();
                    std::cout << "Saved.\n\n";
                    Color::resetTextColor();
                    break;
                }
            }
        }

        void inputBusArrivalTime() {
            while (true) {
                std::cout << "Enter Bus's Arrival Time: ";
                getline(std::cin, input);
                if (b.setArrivalTime(input)) {
                    Color::setGreenTextColor();
                    std::cout << "Saved.\n\n";
                    Color::resetTextColor();
                    break;
                }
            }
        }

        Bus getBusDetils() {
            return b;
        }
};

class BusDetailsDisplay {
private:
    Bus b; // Bus instance to retrieve details
public:
    // Constructor
    BusDetailsDisplay(const Bus &bus) {
        b = bus;
    }

    // Function to display all bus details
    void displayBusDetails() const {
        Color::setBlueTextColor();
        std::cout << "------------------------ Bus Details ------------------------\n";
        Color::resetTextColor();

        std::cout << "Bus ID: " << b.getBusID() << "\n";
        std::cout << "Number Plate: " << b.getNumberPlate() << "\n";
        std::cout << "Total Seats: " << b.getTotalSeats() << "\n";
        std::cout << "Bus Type: " << b.getBusType() << "\n";
        std::cout << "Fare: " << b.getFare() << "\n";

        std::cout << "Driver Name: " << b.getDriverName() << "\n";
        std::cout << "Driver Phone Number: " << b.getDriverNumber() << "\n";
        std::cout << "Driver Age: " << b.getDriverAge() << "\n";

        std::cout << "Departure City: " << b.getDepartureCity() << "\n";
        std::cout << "Departure Time: " << b.getDepartureTime() << "\n";
        std::cout << "Arrival City: " << b.getArrivalCity() << "\n";
        std::cout << "Arrival Time: " << b.getArrivalTime() << "\n";

        Color::setBlueTextColor();
        std::cout << "------------------------------------------------------------\n";
        Color::resetTextColor();
    }
};

int main() {
    BusDetailsInput b;
    /*b.inputBusID();
    b.inputBusNumberPlate();
    b.inputBusTotalSeats();
    b.inputBusType();
    b.inputBusFare();
    b.inputBusDriverName();
    b.inputBusDriverNumber();
    b.inputBusDriverAge();*/
    b.inputBusDepartureCity();
    b.inputBusDepartureTime();
    b.inputBusArrivalCity();
    b.inputBusArrivalTime();

    BusDetailsDisplay d(b.getBusDetils());
    d.displayBusDetails();
    return 0;
}