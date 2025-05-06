#include<iostream>
#include<string>
#include<conio.h>
#include<windows.h>
#include<fstream>



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
};

class UserDetails {
private:	
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	std::string mobilePhoneNumber;
	std::string username;
	std::string password;

public:
	// Default Constructor
	UserDetails() {
		firstName = "NULL\n";
		lastName = "NULL\n";
		emailAddress = "NULL\n";
		mobilePhoneNumber = "NULL\n";
		username = "NULL\n";
		password = "NULL\n";
	}

	// Mutators
	bool setFirstName(const std::string& temp) {
		if (temp.empty()) {
			Color::setRedTextColor();
			std::cout << "Error: Name cannot be empty.\n\n";
			Color::resetTextColor();
			return false;
		}

		if (temp.length() > 50) {
			Color::setRedTextColor();
			std::cout << "Error: Name cannot exceed 50 characters.\n\n";
			Color::resetTextColor();
			return false;
		}

		for (char ch : temp) {
			if (ch == ' ') {
				Color::setRedTextColor();
				std::cout << "Error: Name must not contain spaces.\n\n";
				Color::resetTextColor();
				return false;
			}
			else if (isdigit(ch)) {
				Color::setRedTextColor();
				std::cout << "Error: Name must not contain digits.\n\n";
				Color::resetTextColor();
				return false;
			}
			else if (!isalpha(ch)) {
				Color::setRedTextColor();
				std::cout << "Error: Name must not contain special characters.\n\n";
				Color::resetTextColor();
				return false;
			}
		}

		firstName = temp;
		return true;
	}

	bool setLastName(const std::string& temp) {
		if (temp.empty()) {
			Color::setRedTextColor();
			std::cout << "Error: Last name cannot be empty.\n\n";
			Color::resetTextColor();
			return false;
		}

		if (temp.length() > 50) {
			Color::setRedTextColor();
			std::cout << "Error: Last name cannot exceed 50 characters.\n\n";
			Color::resetTextColor();
			return false;
		}

		for (char ch : temp) {
			if (ch == ' ') {
				Color::setRedTextColor();
				std::cout << "Error: Last name must not contain spaces.\n\n";
				Color::resetTextColor();
				return false;
			}
			else if (isdigit(ch)) {
				Color::setRedTextColor();
				std::cout << "Error: Last name must not contain digits.\n\n";
				Color::resetTextColor();
				return false;
			}else if (ch == '_'){
				continue;
			}
			else if (!isalpha(ch)) {
				Color::setRedTextColor();
				std::cout << "Error: Last name must not contain special characters.\n\n";
				Color::resetTextColor();
				return false;
			}
		}

		lastName = temp;
		return true;
	}

	bool setEmail(std::string& temp) {
		if (temp.empty()) {
			Color::setRedTextColor();
			std::cout << "Error: Email address cannot be empty.\n\n";
			Color::resetTextColor();
			return false;
		}

		if (temp.length() > 320) {
			Color::setRedTextColor();
			std::cout << "Error: Email address exceeds the maximum allowed length (320 characters).\n\n";
			Color::resetTextColor();
			return false;
		}

		for (char ch : temp) {
			if (ch == ' ') {
				Color::setRedTextColor();
				std::cout << "Error: Email address must not contain spaces.\n\n";
				Color::resetTextColor();
				return false;
			}
		}


		// npos is the value that is returned when the charector is not present in the string

		if (temp.find('@') == std::string::npos || temp.find('.') == std::string::npos ) {
			Color::setRedTextColor();
			std::cout << "Error: Invalid email format. Expected format: example@domain.com\n\n";
			Color::resetTextColor();
			return false;
		}
		
		//addition
		//for validating duplicate emails
		
		
		std::ifstream read("UserData.txt");
		std::string tempDetails[6]; // for user deatils
		while(read>>tempDetails[0]>>tempDetails[1]>>tempDetails[2]>>tempDetails[3]>>tempDetails[4]>>tempDetails[5]){
			if(temp==tempDetails[4]){
				Color::setRedTextColor();
				std::cout<<"Email already exist\n\n";
				Color::resetTextColor();
				return false;
			}
		}

		emailAddress = temp;
		return true;
	}

	bool setMobilePhoneNumber(const std::string& temp) {
		if (temp.empty()) {
			Color::setRedTextColor();
			std::cout << "Error: Mobile phone number cannot be empty.\n\n";
			Color::resetTextColor();
			return false;
		}

		for (char ch : temp) {
			if (ch == ' ') {
				Color::setRedTextColor();
				std::cout << "Error: Mobile phone number must not contain spaces.\n\n";
				Color::resetTextColor();
				return false;
			}
			else if (isalpha(ch)) {
				Color::setRedTextColor();
				std::cout << "Error: Mobile phone number must not contain letters.\n\n";
				Color::resetTextColor();
				return false;
			}
			else if (!isdigit(ch)) {
				Color::setRedTextColor();
				std::cout << "Error: Mobile phone number must not contain special characters.\n\n";
				Color::resetTextColor();
				return false;
			}
		}

		if (temp.length() != 11) {
			Color::setRedTextColor();
			std::cout << "Error: Mobile phone number must be exactly 11 digits.\n\n";
			Color::resetTextColor();
			return false;
		}
		
		//addition
		//for validating duplicate phone No
		
		
		std::ifstream read("UserData.txt");
		std::string tempDetails[6]; // for user deatils
		while(read>>tempDetails[0]>>tempDetails[1]>>tempDetails[2]>>tempDetails[3]>>tempDetails[4]>>tempDetails[5]){
			if(temp==tempDetails[5]){
				Color::setRedTextColor();
				std::cout<<"Phonr already exist\n\n";
				Color::resetTextColor();
				return false;
			}
		}
		
		mobilePhoneNumber = temp;
		return true;
	}

	bool setUsername(const std::string& temp) {
		if (temp.empty()) {
			Color::setRedTextColor();
			std::cout << "Error: Username cannot be empty.\n\n";
			Color::resetTextColor();
			return false;
		}
		for (char ch : temp) {
			if (ch == ' ') {
				Color::setRedTextColor();
				std::cout << "Error: Username must not contain spaces.\n\n";
				Color::resetTextColor();
				return false;
			}
		}
		
		//addition
		//for validating duplicate usernames
		
		
		std::ifstream read("UserData.txt");
		std::string tempDetails[6]; // for user deatils
		while(read>>tempDetails[0]>>tempDetails[1]>>tempDetails[2]>>tempDetails[3]>>tempDetails[4]>>tempDetails[5]){
			
			if(temp==tempDetails[0]){
				Color::setRedTextColor();
				std::cout<<"Username already exist\n\n";
				Color::resetTextColor();
				return false;
			}
		}
		
		if ((isalpha(temp[0]) || temp[0] == '_') &&
	        (temp.back() == '_' || isalpha(temp.back()) || isdigit(temp.back()))) {
	        username = temp;
	        return true;
	    } 

		else {
			Color::setRedTextColor();
			std::cout << "Error: Username cannot start or end with special charectors.\n\n";
			Color::resetTextColor();
			return false;
		}
	}

	bool setPassword(const std::string& temp) {
		if (temp.empty()) {
			Color::setRedTextColor();
			std::cout << "Error: Password cannot be empty.\n\n";
			Color::resetTextColor();
			return false;
		}

		if (temp.length() < 8) {
			Color::setRedTextColor();
			std::cout << "Error: Password must be atleast 8 characters.\n\n";
			Color::resetTextColor();
			return false;
		}

		if (temp.length() > 40) {
			Color::setRedTextColor();
			std::cout << "Error: Name cannot exceed 40 characters.\n\n";
			Color::resetTextColor();
			return false;
		}

		bool checkContain = true;


		for (char ch : temp) {
			if (isalpha(ch)) {
				checkContain = false;
			}
		}

		if (checkContain) {
			Color::setRedTextColor();
			std::cout << "Error: Password must contain characters.\n\n";
			Color::resetTextColor();
			return false;
		}
		for (char ch : temp) {
			if (ch == ' ') {
				Color::setRedTextColor();
				std::cout << "Error: Password must not contain spaces.\n\n";
				Color::resetTextColor();
				return false;
			}
		}

		checkContain = true;

		for (char ch : temp) {
			if (isdigit(ch)) {
				checkContain = false;
			}
		}

		if (checkContain) {
			Color::setRedTextColor();
			std::cout << "Error: Password must contain atleast 1 digit.\n\n";
			Color::resetTextColor();
			return false;
		}

		checkContain = true;
		for (char ch : temp) {
			if (!isdigit(ch) and !isalpha(ch)) {
				checkContain = false;
			}
		}


		if (checkContain) {
			Color::setRedTextColor();
			std::cout << "Error: Password must contain atleast 1 special characters.\n\n";
			Color::resetTextColor();
			return false;
		}


		password = temp;
		return true;

	}


	std::string getFirstName() const {
		return firstName;
	}
	std::string getLastName() const {
		return lastName;
	}
	std::string getEmail() {
		return emailAddress;
	}
	std::string getMobilePhoneNumber() const {
		return mobilePhoneNumber;
	}
	std::string getUsername() const {
		return username;
	}
	std::string getPassword() const {
		return password;
	}

};

class UserInputs {
private:
	UserDetails u;
	std::string temp;
public:


	void inputFirstName() {
		temp.clear();
		while (true) {
			std::cout << "Enter First Name: ";
			std::getline(std::cin, temp);

			if (u.setFirstName(temp)) {
				Color::setGreenTextColor();
				std::cout << "Saved\n";
				Color::resetTextColor();
				break;
			}
		}
		std::cout << "First Name: " << u.getFirstName() << std::endl << std::endl;
	}

	void inputLastName() {
		temp.clear();
		while (true) {
			std::cout << "Enter Last Name: ";
			std::getline(std::cin, temp);

			if (u.setLastName(temp)) {
				Color::setGreenTextColor();
				std::cout << "Saved\n";
				Color::resetTextColor();
				break;
			}
		}
		std::cout << "Last Name: " << u.getLastName() << std::endl << std::endl;
	}

	void inputUserName() {
		temp.clear();
		while (true) {
			std::cout << "Enter Username: ";
			getline(std::cin, temp);

			if (u.setUsername(temp)) {
				Color::setGreenTextColor();
				std::cout << "Saved\n";
				Color::resetTextColor();
				break;
			}

		}
		std::cout << "Username: " << u.getUsername() << std::endl << std::endl;
	}

	void inputEmail() {
		temp.clear();
		while (true) {
			std::cout << "Enter Email: ";
			std::getline(std::cin, temp);

			if (u.setEmail(temp)) {
				Color::setGreenTextColor();
				std::cout << "Saved\n";
				Color::resetTextColor();
				break;
			}
		}
		std::cout << "Email: " << u.getEmail() << std::endl << std::endl;
	}

	void inputPhoneNumber() {
		temp.clear();
		while (true) {
			std::cout << "Enter Mobile Phone Number: ";
			std::getline(std::cin, temp);

			if (u.setMobilePhoneNumber(temp)) {
				Color::setGreenTextColor();
				std::cout << "Saved\n";
				Color::resetTextColor();
				break;
			}
		}
		std::cout << "Mobile Phone Number: " << u.getMobilePhoneNumber() << std::endl << std::endl;
	}

	void inputPassword() {
		char ch;
		while (true) {
			temp.clear();
			std::cout << "Enter Password: ";
			while (ch = _getch()) {
				if (ch == '\r') {
					std::cout << std::endl;
					break;
				}
				else if (ch == '\b' && !temp.empty()) {
					std::cout << "\b \b";
					temp.pop_back();
				}
				else {
					temp += ch;
					std::cout << "*";
				}
			}

			if (u.setPassword(temp)) {
				Color::setGreenTextColor();
				std::cout << "Saved\n";
				Color::resetTextColor();
				break;
			}
			else {
			}

			continue;
		}
		std::cout << "Password: " << u.getPassword() << std::endl << std::endl;
	}

	void inputConfirmedPassword() {
		temp.clear();
		while (true) {
			temp.clear();
			std::cout << "Confirm Password: ";
			char ch;
			while ((ch = _getch())) {
				if (ch == '\r') {
					std::cout << std::endl;
					break;
				}
				else if (ch == '\b' && !temp.empty()) { // Handle backspace
					std::cout << "\b \b";
					temp.pop_back();
				}
				else {
					temp += ch;
					std::cout << "*";
				}
			}
			std::cout << std::endl;

			if (temp == u.getPassword()) {
				Color::setGreenTextColor();
				std::cout << "Password Confirmed!\n";
				Color::resetTextColor();
				break;
			}
			else {
				Color::setRedTextColor();
				std::cout << "Error: Passwords do not match. Try again.\n\n";
				Color::resetTextColor();
			}
		}
	}

	void displayUserData (){
		
		std::cout << "\n===User Details===\n";
	    std::cout << "First Name: " << u.getFirstName() << "\n";
	    std::cout << "Last Name: "  << u.getLastName() << "\n";
	    std::cout << "Email: "      << u.getEmail();
	    std::cout << "Mobile: "     << u.getMobilePhoneNumber() << "\n";
	    std::cout << "Username: "   << u.getUsername() << "\n";
	    std::cout << "Password: "   << u.getPassword()   << "\n";
	    
	}
	
	bool saveUserDataOnFile(){
		
		if (u.getFirstName()=="NULL"){
			std::cout<<"First name is missing.\n";
			return false;
			
		}else if (u.getLastName()=="NULL"){
			std::cout<<"Last name is missing.\n";
			return false;
			
		}else if (u.getEmail()=="NULL"){
			std::cout<<"Email is missing.\n";
			return false;
		
		}else if (u.getMobilePhoneNumber()=="NULL"){
			std::cout<<"Phone Number is missing.\n";
			return false;
		
		}else if (u.getUsername()=="NULL"){
			std::cout<<"Username is missing.\n";
			return false;
		
		}else if (u.getPassword()=="NULL"){
			std::cout<<"Password name is missing.\n";
			return false;
		}
		
		std::ofstream write("UserData.txt" , std::ios::app);
		write << u.getUsername()<<" "<<u.getPassword()<<" "<<u.getFirstName()<<" "<<u.getLastName()
		<<" "<<u.getEmail()<<" "<<u.getMobilePhoneNumber()<<"\n";
		write.close();
		std::cout<<"saved";
		return true;
	}
};


class PaymentDetails {
private:
    std::string cardNumber;
    std::string expiryDate;
    std::string cvv;
    std::string nameOnCard;

public:
    // Setters
    bool setCardNumber(const std::string& temp) {
		if (temp.empty()) {
			Color::setRedTextColor();
			std::cout << "Error: Card number cannot be empty.\n\n";
			Color::resetTextColor();
			return false;
		}

		for (char ch : temp) {
			if (ch == ' ') {
				Color::setRedTextColor();
				std::cout << "Error: Card number must not contain spaces.\n\n";
				Color::resetTextColor();
				return false;
			}
			else if (isalpha(ch)) {
				Color::setRedTextColor();
				std::cout << "Error: Card number must not contain letters.\n\n";
				Color::resetTextColor();
				return false;
			}
			else if (!isdigit(ch)) {
				Color::setRedTextColor();
				std::cout << "Error: Card number must not contain special characters.\n\n";
				Color::resetTextColor();
				return false;
			}
		}

		if (temp.length() != 16) {
			Color::setRedTextColor();
			std::cout << "Error: Card number must be exactly 16 digits.\n\n";
			Color::resetTextColor();
			return false;
		}
		
		
		cardNumber = temp;
		return true;
    	
    }

    bool setExpiryDate(const std::string& temp) {
    	
    	if (temp.empty()) {
			Color::setRedTextColor();
			std::cout << "Error: Expiry Date cannot be empty.\n\n";
			Color::resetTextColor();
			return false;
		}
		for (char ch : temp) {
			if (ch == ' ') {
				Color::setRedTextColor();
				std::cout << "Error: Expiry Date must not contain spaces.\n\n";
				Color::resetTextColor();
				return false;
			}
			else if (isalpha(ch)) {
				Color::setRedTextColor();
				std::cout << "Error: Expiry Date must not contain letters.\n\n";
				Color::resetTextColor();
				return false;
			}
		}
		
		if (temp.length() != 10){
			Color::setRedTextColor();
			std::cout << "Error: Expiry Date must follow proper format (dd/mm/yyyy).\n\n";
			Color::resetTextColor();
			return false;
		}
		
    	if (temp[2] != '/' || temp[5] != '/'){
    		Color::setRedTextColor();
			std::cout << "Error: Expiry Date must follow proper format (dd/mm/yyyy).\n\n";
			Color::resetTextColor();
			return false;
		}
		
        expiryDate = temp;
        return true;
    }

    bool setCVV(const std::string& temp) {
	    if (temp.empty()) {
	        Color::setRedTextColor();
	        std::cout << "Error: CVV cannot be empty.\n\n";
	        Color::resetTextColor();
	        return false;
	    }
	
	    for (char ch : temp) {
	        if (ch == ' ') {
	            Color::setRedTextColor();
	            std::cout << "Error: CVV must not contain spaces.\n\n";
	            Color::resetTextColor();
	            return false;
	        }
	        else if (isalpha(ch)) {
	            Color::setRedTextColor();
	            std::cout << "Error: CVV must not contain letters.\n\n";
	            Color::resetTextColor();
	            return false;
	        }
	        else if (!isdigit(ch)) {
	            Color::setRedTextColor();
	            std::cout << "Error: CVV must not contain special characters.\n\n";
	            Color::resetTextColor();
	            return false;
	        }
	    }
	
	    if (temp.length() != 3 && temp.length() != 4) {
	        Color::setRedTextColor();
	        std::cout << "Error: CVV must be exactly 3 or 4 digits.\n\n";
	        Color::resetTextColor();
	        return false;
	    }
	
	    cvv = temp;
	    return true;
	}

	bool setNameOnCard(const std::string& temp) {
	    if (temp.empty()) {
	        Color::setRedTextColor();
	        std::cout << "Error: Name on card cannot be empty.\n\n";
	        Color::resetTextColor();
	        return false;
	    }
	
	    if (temp.length() > 50) {
	        Color::setRedTextColor();
	        std::cout << "Error: Name on card cannot exceed 50 characters.\n\n";
	        Color::resetTextColor();
	        return false;
	    }
	
	    for (char ch : temp) {
	        if (ch == ' ') {
	            Color::setRedTextColor();
	            std::cout << "Error: Name on card must not contain spaces.\n\n";
	            Color::resetTextColor();
	            return false;
	        } else if (isdigit(ch)) {
	            Color::setRedTextColor();
	            std::cout << "Error: Name on card must not contain digits.\n\n";
	            Color::resetTextColor();
	            return false;
	        } else if (ch == '_') {
	            continue;
	        } else if (!isalpha(ch)) {
	            Color::setRedTextColor();
	            std::cout << "Error: Name on card must not contain special characters.\n\n";
	            Color::resetTextColor();
	            return false;
	        }
	    }
	
	    nameOnCard = temp;
	    return true;
	}



    

    // Getters
    std::string getCardNumber() const { 
		return cardNumber; 
	}
    std::string getExpiryDate() const { 
		return expiryDate; 
	}
    std::string getCVV() const { 
		return cvv; 
	}
    
    std::string getNameOnCard() const { 
		return nameOnCard; 
	}
	
	
	
};

class PaymentInputs {
private:	
	PaymentDetails p;
	std::string temp;
public:	
	void inputCardNumber(){
		temp.clear();
		while (true) {
			std::cout << "Enter Card Number: ";
			std::getline(std::cin, temp);

			if (p.setCardNumber(temp)) {
				Color::setGreenTextColor();
				std::cout << "Saved\n";
				Color::resetTextColor();
				break;
			}
		}
		std::cout << "Card Number: " << p.getCardNumber() << std::endl << std::endl;
		
	}

	void inputExpiryDate (){
		temp.clear();
		while (true) {
			std::cout << "Enter Expiry Date (dd/mm/yyyy): ";
			std::getline(std::cin, temp);

			if (p.setExpiryDate(temp)) {
				Color::setGreenTextColor();
				std::cout << "Saved\n";
				Color::resetTextColor();
				break;
			}
		}
		std::cout << "Expiry Date: " << p.getExpiryDate() << std::endl << std::endl;
	}
	
	void inputCVV (){
		temp.clear();
		while (true) {
			std::cout << "Enter CVV (Card Verification Value): ";
			std::getline(std::cin, temp);

			if (p.setCVV(temp)) {
				Color::setGreenTextColor();
				std::cout << "Saved\n";
				Color::resetTextColor();
				break;
			}
		}
		std::cout << "CVV: " << p.getCVV() << std::endl << std::endl;
	}
	void inputNameOnCard() {
	    temp.clear();
	    while (true) {
	        std::cout << "Enter Name on Card: ";
	        std::getline(std::cin, temp);
	
	        if (p.setNameOnCard(temp)) {
	            Color::setGreenTextColor();
	            std::cout << "Saved\n";
	            Color::resetTextColor();
	            break;
	        }
	    }
	    std::cout << "Name on Card: " << p.getNameOnCard() << "\n\n";
	}
	
	bool savePaymentDataOnFile() {
	    if (p.getNameOnCard().empty()) {
	        std::cout << "Name on card is missing.\n";
	        return false;
	    }
	    else if (p.getCardNumber().empty()) {
	        std::cout << "Card number is missing.\n";
	        return false;
	    }
	    else if (p.getExpiryDate().empty()) {
	        std::cout << "Expiry date is missing.\n";
	        return false;
	    }
	    else if (p.getCVV().empty()) {
	        std::cout << "CVV is missing.\n";
	        return false;
	    }
	    std::ofstream write("PaymentData.txt", std::ios::app);
	    write << p.getCardNumber() << " "<< p.getExpiryDate() << " "
	          << p.getCVV() << " "<< p.getNameOnCard() << "\n";
	    write.close();
	
	    std::cout << "saved";
	    return true;
	}
	
};
	
class 

int main() {
	
	
	
	

	return 0;
}