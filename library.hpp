class User {
    std::string name;
    std::string emailAddress;
    std::string mobilePhoneNumber;
    std::string username;
    std::string password;
    std::string confirmPassword;

public:
    // Default Constructor
    User() {
        name="NULL\n";
        emailAddress = "NULL\n";
        mobilePhoneNumber = "NULL\n";
        username = "NULL\n";
        password = "NULL\n";
        confirmPassword = "NULL\n";
    }

    // Parameterized Constructor
    User(const std::string& name, const std::string& email,
        const std::string& phone, const std::string& user, 
        const std::string& pass, const std::string& confirmPass) {
        
		this->name = name;
        emailAddress = email;
        mobilePhoneNumber = phone;
        username = user;
        password = pass;
        confirmPassword = confirmPass;
    }

    // Mutators
	bool setName(const std::string& temp) {
	    if (temp.empty()) {
	        std::cout << "First name cannot be empty!\n";
	        return false;
	    }
	    
	    if (temp.length() > 50){
	        std::cout << "First name is too long!\n";
	        return false;
	    }
	    
	    for (char ch : temp) {
	        if (ch == ' ') {
	            std::cout << "First name cannot contain spaces.\n";
	            return false;
	        } else if (isdigit(ch)) {
	            std::cout << "First name cannot contain numbers.\n";
	            return false;
	        } else if (!isalpha(ch)) {
	            std::cout << "First name cannot contain special characters.\n";
	            return false;
	        }
	    }
	    name = temp;
	    return true;
	}
	
	std::string getName() const { 
        return name; 
    }
    
    bool setEmail(std::string& temp){
    	
    	if (temp.empty()) {
	        std::cout << "Email cannot be empty!\n";
	        return false;
	    }
	    
	    if (temp.length() > 320){
	        std::cout << "Email is too long!\n";
	        return false;
	    }
	    
	    for (char ch : temp) {
	        if (ch == ' ') {
	            std::cout << "Email cannot contain spaces.\n";
	            return false;
	        }
	    }
	
	    if (temp.find('@')==std::string::npos || temp.find('.')==std::string::npos ){
		    std::cout <<"Email must follow the defined format (abc@example.com)\n";
			return false;
		}
		
	emailAddress=temp;
	return true;
	}
	
	std::string getEmail(){
		return emailAddress;
	}
    
	
};