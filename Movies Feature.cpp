#include<iostream>		// iske bager guzara nhi c++ mai 
#include<string>  		// assy lga di 
#include<windows.h>		// colors add krne keliye 
#include<fstream> 		// file handling 


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



class MovieDetails {
private:
    std::string title;
    std::string genre;
    std::string duration; 
    std::string rating;

public:
    bool setTitle(const std::string& temp) {
		if (temp.empty()) {
			Color::setRedTextColor();
			std::cout << "Error: Movie title cannot be empty.\n\n";
			Color::resetTextColor();
			return false;
		}
	
		if (temp.length() < 2) {
			Color::setRedTextColor();
			std::cout << "Error: Movie title must be at least 2 characters long.\n\n";
			Color::resetTextColor();
			return false;
		}
	
		if (temp.length() > 100) {
			Color::setRedTextColor();
			std::cout << "Error: Movie title cannot exceed 100 characters.\n\n";
			Color::resetTextColor();
			return false;
		}
	
		for (char ch : temp) {
			if(ch==' '){
				Color::setRedTextColor();
				std::cout << "Error: Empty spaces are not allowed. Please use underscores (_) instead.\n\n";
				Color::resetTextColor();
				return false;
			}
			
			if (!isalnum(ch) && ch != '_' && ch != ':' && ch != '-') {
				Color::setRedTextColor();
				std::cout << "Error: Movie title contains invalid characters.\n\n";
				Color::resetTextColor();
				return false;
			}
		}
	
		title = temp;
		return true;
	}

    void setGenre(const std::string& temp){
    	genre=temp;
	}
	
    void setDuration(const std::string& d){
    	duration=d;
	}
    void setRating(const std::string& r){
    	rating= r;	
	}

    std::string getTitle() const {
    	return title;
	}
    std::string getGenre() const {
    	return genre;
	}
    std::string getDuration() const {
    	return duration;
	}
    std::string getRating() const {
    	return rating;
	}
};

class Menu {
public:
	static void displayGenres() {
	    std::cout << "\n============== AVAILABLE GENRES ==============\n";
	    std::cout << " 1. Action          - High-paced, intense sequences.\n";
	    std::cout << " 2. Adventure       - Exploration, quests, and daring journeys.\n";
	    std::cout << " 3. Comedy          - Light-hearted and humorous content.\n";
	    std::cout << " 4. Drama           - Realistic characters and emotional stories.\n";
	    std::cout << " 5. Horror          - Designed to scare and thrill.\n";
	    std::cout << " 6. Science Fiction - Futuristic and speculative scenarios.\n";
	    std::cout << " 7. Romance         - Love-centered narratives.\n";
	    std::cout << " 8. Thriller        - Suspense, mystery, and plot twists.\n";
	    std::cout << " 9. Animation       - Stylized visuals, often family-oriented.\n";
	    std::cout << "10. Fantasy         - Magical worlds and mythical elements.\n";
	    std::cout << "11. Mystery         - Solving crimes or uncovering secrets.\n";
	    std::cout << "12. Crime           - Focus on criminal activities or investigations.\n";
	    std::cout << "13. Musical         - Storytelling through song and dance.\n";
	    std::cout << "14. Documentary     - Factual, real-world subject matter.\n";
	    std::cout << "15. Historical      - Set in a specific time period from history.\n";
	    std::cout << "16. War             - Centered on military conflict.\n";
	    std::cout << "17. Western         - Set in the American frontier.\n";
	    std::cout << "18. Biography       - Based on a real person's life.\n";
	    std::cout << "==============================================\n";
	}
		
	static void displayDurations() {
		std::cout << "\n========== MOVIE DURATIONS ==========\n";
		std::cout << " 1. Short Film     - Under 40 minutes.\n";
		std::cout << " 2. Standard Film  - 90 to 120 minutes.\n";
		std::cout << " 3. Extended Film  - 120 to 150 minutes.\n";
		std::cout << " 4. Epic Feature   - Over 150 minutes.\n";
		std::cout << "=====================================\n";
	}
		
	static void displayRatings() {
		std::cout << "\n=========== MOVIE RATINGS ===========\n";
		std::cout << " 1. G      - General Audience (All Ages)\n";
		std::cout << " 2. PG     - Parental Guidance Suggested\n";
		std::cout << " 3. PG-13  - Parents Strongly Cautioned\n";
		std::cout << " 4. R      - Restricted (17+ with guardian)\n";
		std::cout << " 5. NC-17  - Adults Only (18 and above)\n";
		std::cout << "======================================\n";
	}
	
};

class MovieInput{
	MovieDetails movie;
	std::string temp;
public:	
	void inputTitle() {
		temp.clear();
		while (true) {
			std::cout << "Enter Movie Title: ";
			std::getline(std::cin, temp);
	
			if (movie.setTitle(temp)) {
				Color::setGreenTextColor();
				std::cout << "Saved\n";
				Color::resetTextColor();
				break;
			}
		}
		std::cout << "Movie Title: " << movie.getTitle() << "\n\n";
	}

	void inputGenre() {
	    temp.clear();
	    Menu::displayGenres();
	    std::string choice;
	
	    while (true) {
	        std::cout << "Select genre (1-18): ";
	        getline(std::cin, choice);
	
	        if (choice == "1") {
	            movie.setGenre("Action");
	            break;
	        } else if (choice == "2") {
	            movie.setGenre("Adventure");
	            break;
	        } else if (choice == "3") {
	            movie.setGenre("Comedy");
	            break;
	        } else if (choice == "4") {
	            movie.setGenre("Drama");
	            break;
	        } else if (choice == "5") {
	            movie.setGenre("Horror");
	            break;
	        } else if (choice == "6") {
	            movie.setGenre("Science Fiction");
	            break;
	        } else if (choice == "7") {
	            movie.setGenre("Romance");
	            break;
	        } else if (choice == "8") {
	            movie.setGenre("Thriller");
	            break;
	        } else if (choice == "9") {
	            movie.setGenre("Animation");
	            break;
	        } else if (choice == "10") {
	            movie.setGenre("Fantasy");
	            break;
	        } else if (choice == "11") {
	            movie.setGenre("Mystery");
	            break;
	        } else if (choice == "12") {
	            movie.setGenre("Crime");
	            break;
	        } else if (choice == "13") {
	            movie.setGenre("Musical");
	            break;
	        } else if (choice == "14") {
	            movie.setGenre("Documentary");
	            break;
	        } else if (choice == "15") {
	            movie.setGenre("Historical");
	            break;
	        } else if (choice == "16") {
	            movie.setGenre("War");
	            break;
	        } else if (choice == "17") {
	            movie.setGenre("Western");
	            break;
	        } else if (choice == "18") {
	            movie.setGenre("Biography");
	            break;
	        } else {
	            Color::setRedTextColor();
	            std::cout << "Error: Invalid choice!!\n\n";
	            Color::resetTextColor();
	        }
	    }
	
	    std::cout << "Genre: " << movie.getGenre() << "\n";
	}
	

	
};



class Interface {
public:
	static void MovieFeature(){
		MovieInput movie;
		movie.inputTitle();
		movie.inputGenre();
	}
	
	
};


int main() {
	Interface::MovieFeature();
	
	
	

	return 0;
}