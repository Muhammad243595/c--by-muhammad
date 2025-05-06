#include<iostream>
#include<windows.h>

void setRedTextColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void resetTextColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

class User {
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    std::string mobilePhoneNumber;
    std::string username;
    std::string password;
    std::string confirmPassword;

public:
    // Default Constructor
    User() {
        firstName="NULL\n";
        lastName="NULL\n";
        emailAddress = "NULL\n";
        mobilePhoneNumber = "NULL\n";
        username = "NULL\n";
        password = "NULL\n";
        confirmPassword = "NULL\n";
    }

    // Parameterized Constructor
    User(const std::string& name,const std::string& lname, const std::string& email,
        const std::string& phone, const std::string& user, 
        const std::string& pass, const std::string& confirmPass) {
        
		firstName = name;
		lastName = lname;
        emailAddress = email;
        mobilePhoneNumber = phone;
        username = user;
        password = pass;
        confirmPassword = confirmPass;
    }
    
    
		// Mutators
	bool setFirstName(const std::string& temp) {
	    if (temp.empty()) {
	        setRedTextColor();
	        std::cout << "Error: Name cannot be empty.\n";
	        resetTextColor();
	        return false;
	    }
	
	    if (temp.length() > 50) {
	        setRedTextColor();
	        std::cout << "Error: Name cannot exceed 50 characters.\n";
	        resetTextColor();
	        return false;
	    }
	
	    for (char ch : temp) {
	        if (ch == ' ') {
	            setRedTextColor();
	            std::cout << "Error: Name must not contain spaces.\n";
	            resetTextColor();
	            return false;
	        } else if (isdigit(ch)) {
	            setRedTextColor();
	            std::cout << "Error: Name must not contain digits.\n";
	            resetTextColor();
	            return false;
	        } else if (!isalpha(ch)) {
	            setRedTextColor();
	            std::cout << "Error: Name must not contain special characters.\n";
	            resetTextColor();
	            return false;
	        }
	    }
	
	    firstName = temp;
	    return true;
	}
	
	bool setLastName(const std::string& temp) {
	    if (temp.empty()) {
	        setRedTextColor();
	        std::cout << "Error: Last name cannot be empty.\n";
	        resetTextColor();
	        return false;
	    }
	
	    if (temp.length() > 50) {
	        setRedTextColor();
	        std::cout << "Error: Last name cannot exceed 50 characters.\n";
	        resetTextColor();
	        return false;
	    }
	
	    for (char ch : temp) {
	        if (ch == ' ') {
	            setRedTextColor();
	            std::cout << "Error: Last name must not contain spaces.\n";
	            resetTextColor();
	            return false;
	        } else if (isdigit(ch)) {
	            setRedTextColor();
	            std::cout << "Error: Last name must not contain digits.\n";
	            resetTextColor();
	            return false;
	        } else if (!isalpha(ch)) {
	            setRedTextColor();
	            std::cout << "Error: Last name must not contain special characters.\n";
	            resetTextColor();
	            return false;
	        }
	    }
	
	    lastName = temp;
	    return true;
	}
	
	bool setEmail(std::string& temp) {
	    if (temp.empty()) {
	        setRedTextColor();
	        std::cout << "Error: Email address cannot be empty.\n";
	        resetTextColor();
	        return false;
	    }
	
	    if (temp.length() > 320) {
	        setRedTextColor();
	        std::cout << "Error: Email address exceeds the maximum allowed length (320 characters).\n";
	        resetTextColor();
	        return false;
	    }
	
	    for (char ch : temp) {
	        if (ch == ' ') {
	            setRedTextColor();
	            std::cout << "Error: Email address must not contain spaces.\n";
	            resetTextColor();
	            return false;
	        }
	    }
	
	    if (temp.find('@') == std::string::npos || temp.find('.') == std::string::npos) {
	        setRedTextColor();
	        std::cout << "Error: Invalid email format. Expected format: example@domain.com\n";
	        resetTextColor();
	        return false;
	    }
	
	    emailAddress = temp;
	    return true;
	}
	
	bool setMobilePhoneNumber(const std::string& temp) {
	    if (temp.empty()) {
	        setRedTextColor();
	        std::cout << "Error: Mobile phone number cannot be empty.\n\n";
	        resetTextColor();
	        return false;
	    }
	
	    for (char ch : temp) {
	        if (ch == ' ') {
	            setRedTextColor();
	            std::cout << "Error: Mobile phone number must not contain spaces.\n";
	            resetTextColor();
	            return false;
	        } else if (isalpha(ch)) {
	            setRedTextColor();
	            std::cout << "Error: Mobile phone number must not contain letters.\n";
	            resetTextColor();
	            return false;
	        } else if (!isdigit(ch)) {
	            setRedTextColor();
	            std::cout << "Error: Mobile phone number must not contain special characters.\n";
	            resetTextColor();
	            return false;
	        }
	    }
	
	    if (temp.length() != 11) {
	        setRedTextColor();
	        std::cout << "Error: Mobile phone number must be exactly 11 digits.\n";
	        resetTextColor();
	        return false;
	    }
	
	    mobilePhoneNumber = temp;
	    return true;
	}
	
	bool setUsername(const std::string& temp) {
	    if (temp.empty()) {
	        setRedTextColor();
	        std::cout << "Error: Username cannot be empty.\n\n";
	        resetTextColor();
	        return false;
	    }
	    for (char ch : temp) {
	        if (ch == ' ') {
	            setRedTextColor();
	            std::cout << "Error: Username must not contain spaces.\n";
	            resetTextColor();
	            return false;
	        }
	    }
	
	    if ((isalpha(temp[0]) || temp[0] == '_') &&
	        (temp.back() == '_' || isalpha(temp.back()) || isdigit(temp.back()))) {
	        username = temp;
	        return true;
	    } else {
	        setRedTextColor();
	        std::cout << "Error: Username cannot start or end with special characters.\n";
	        resetTextColor();
	        return false;
	    }
	}
	
	bool setPassword(const std::string& temp) {
	    if (temp.empty()) {
	        setRedTextColor();
	        std::cout << "Error: Password cannot be empty.\n";
	        resetTextColor();
	        return false;
	    }
	
	    if (temp.length() < 8) {
	        setRedTextColor();
	        std::cout << "Error: Password must be at least 8 characters.\n";
	        resetTextColor();
	        return false;
	    }
	
	    if (temp.length() > 40) {
	        setRedTextColor();
	        std::cout << "Error: Password cannot exceed 40 characters.\n";
	        resetTextColor();
	        return false;
	    }
	
	    for (char ch : temp) {
	        if (ch == ' ') {
	            setRedTextColor();
	            std::cout << "Error: Password must not contain spaces.\n";
	            resetTextColor();
	            return false;
	        }
	    }
	
	    bool containsDigit = false;
	    for (char ch : temp) {
	        if (isdigit(ch)) {
	            containsDigit = true;
	            break;
	        }
	    }
	    if (!containsDigit) {
	        setRedTextColor();
	        std::cout << "Error: Password must contain at least 1 digit.\n";
	        resetTextColor();
	        return false;
	    }
	
	    bool containsSpecial = false;
	    for (char ch : temp) {
	        if (!isdigit(ch) && !isalpha(ch)) {
	            containsSpecial = true;
	            break;
	        }
	    }
	    if (!containsSpecial) {
	        setRedTextColor();
	        std::cout << "Error: Password must contain at least 1 special character.\n";
	        resetTextColor();
	        return false;
	    }
	
	    password = temp;
	    return true;
	}
	
	bool setConfirmPassword(const std::string& temp) {
	    if (temp == password) {
	        return true;
	    } else {
	        setRedTextColor();
	        std::cout << "Error: Passwords do not match.\n";
	        resetTextColor();
	        return false;
	    }
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



int main (){
	User u;
	std::string phone;
	
	while(true){
		std::cout <<"Enter PAssword: ";
		getline(std::cin,phone);
		
		if(u.setUsername(phone)){
			std::cout <<"Saved\n";
			break;
		}else {
		}
	
			continue;
	}
	std::cout<<"Username: "<<u.getUsername();
	

	
	
	return 0;
}
