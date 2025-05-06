#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <chrono>
#include <iomanip>
#include <algorithm> 
#include <stdexcept> // For handling potential exceptions
#include <limits>     // For numeric_limits<streamsize>::max()

using namespace std;

// Define an enum for game states
enum class GameState {
    MENU,
    PLAYING,
    HIGHSCORES,
    SETTINGS,
    EXIT
};

// Define an enum for game difficulties
enum class Difficulty {
    EASY,
    MEDIUM,
    HARD
};

// Class for representing a player
class Player {
public:
    string name;
    int score;
    Difficulty difficulty;
    chrono::duration<double> bestTime; 

    Player(const string& playerName) : name(playerName), score(0), difficulty(Difficulty::EASY), bestTime(chrono::duration<double>::max()) {}

    void increaseScore() {
        score++;
    }

    friend ostream& operator<<(ostream& os, const Player& player) {
        return os << player.name << ": " << player.score 
                << " (Difficulty: " << to_string(static_cast<int>(player.difficulty)) << ")" 
                << " | Best Time: " << fixed << setprecision(2) << chrono::duration_cast<chrono::seconds>(player.bestTime).count() << " seconds" 
                << endl;
    }
};

// Abstract Game class (for potential future game variations)
class Game {
public:
    virtual bool makeGuess(int guess) = 0; 
    virtual ~Game() {} 
};

// Concrete GuessingGame class
class GuessingGame : public Game {
public:
    int secretNumber;
    Difficulty difficulty;
    chrono::steady_clock::time_point startTime;

    GuessingGame(Difficulty diff) : difficulty(diff) {
        switch (difficulty) {
            case Difficulty::EASY:
                secretNumber = getRandomNumber(1, 100);
                break;
            case Difficulty::MEDIUM:
                secretNumber = getRandomNumber(1, 500);
                break;
            case Difficulty::HARD:
                secretNumber = getRandomNumber(1, 1000);
                break;
            default:
                throw invalid_argument("Invalid difficulty level"); // Handle invalid input
        }
        startTime = chrono::steady_clock::now(); 
    }

    bool makeGuess(int guess) override { 
        if (guess == secretNumber) {
            chrono::steady_clock::time_point endTime = chrono::steady_clock::now();
            chrono::duration<double> gameTime = endTime - startTime;
            cout << "Congratulations! You guessed it!" << endl;
            return true;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Too high! Try again." << endl;
        }
        return false;
    }

private:
    int getRandomNumber(int min, int max) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(min, max);
        return dist(gen);
    }
};

// Game manager class
class GameManager {
public:
    vector<unique_ptr<Player>> players; 
    GameState state;
    unique_ptr<Game> currentGame; 
    Difficulty selectedDifficulty;

    GameManager() : state(GameState::MENU), selectedDifficulty(Difficulty::EASY) {}

    void run() {
        while (state != GameState::EXIT) {
            switch (state) {
                case GameState::MENU:
                    displayMenu();
                    handleMenuSelection();
                    break;
                case GameState::PLAYING:
                    playGame();
                    break;
                case GameState::HIGHSCORES:
                    displayHighscores();
                    break;
                case GameState::SETTINGS:
                    displaySettings();
                    handleSettingsSelection();
                    break;
                default:
                    cerr << "Error: Invalid game state." << endl; 
                    break;
            }
        }
    }

private:
    void displayMenu() {
        cout << "=== Main Menu ===" << endl;
        cout << "1. Play Game" << endl;
        cout << "2. View Highscores" << endl;
        cout << "3. Settings" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
    }

    void handleMenuSelection() {
        int choice;
        while (!(cin >> choice)) { // Handle invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Consume newline character

        switch (choice) {
            case 1:
                state = GameState::PLAYING;
                break;
            case 2:
                state = GameState::HIGHSCORES;
                break;
            case 3:
                state = GameState::SETTINGS;
                break;
            case 4:
                state = GameState::EXIT;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    void playGame() {
        string playerName;
        cout << "Enter your name: ";
        getline(cin, playerName); 

        // Find existing player or create a new one
        auto playerIter = find_if(players.begin(), players.end(), 
                                 [&playerName](const unique_ptr<Player>& p) { return p->name == playerName; });

        if (playerIter != players.end()) {
            // Player already exists, update difficulty
            (*playerIter)->difficulty = selectedDifficulty; 
        } else {
            // Create a new player
            players.push_back(make_unique<Player>(playerName));
        }

        currentGame = make_unique<GuessingGame>(selectedDifficulty); 

        int guess;
        int attempts = 0;

        while (true) {
            cout << "Enter your guess: ";
            while (!(cin >> guess)) { // Handle invalid input
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number: ";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Consume newline character
            attempts++;

            if (currentGame->makeGuess(guess)) {
                players.back()->increaseScore();

                // Update best time if better
                if (chrono::duration_cast<chrono::seconds>(currentGame->startTime - chrono::steady_clock::now()) < 
                    chrono::duration_cast<chrono::seconds>(players.back()->bestTime)) {
                    players.back()->bestTime = currentGame->startTime - chrono::steady_clock::now(); 
                }

                break;
            }
        }

        state = GameState::MENU;
    }

    void displayHighscores() {
        // Sort players by score in descending order
        sort(players.begin(), players.end(), [](const unique_ptr<Player>& a, const unique_ptr<Player>& b) {
            return a->score > b->score || (a->score == b->score && a->bestTime < b->bestTime); 
        });

        cout << "=== Highscores ===" << endl;
        for (const auto& player : players) {
            cout << *player;
        }

        state = GameState::MENU;
    }

    void displaySettings() {
        cout << "=== Settings ===" << endl;
        cout << "1. Easy" << endl;
        cout << "2. Medium" << endl;
        cout << "3. Hard" << endl;
        cout << "Select difficulty level: ";
    }

    void handleSettingsSelection() {
        int choice;
        while (!(cin >> choice)) { // Handle invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Consume newline character

        switch (choice) {
            case 1:
                selectedDifficulty = Difficulty::EASY;
                break;
            case 2:
                selectedDifficulty = Difficulty::MEDIUM;
                break;
            case 3:
                selectedDifficulty = Difficulty::HARD;
                break;
           