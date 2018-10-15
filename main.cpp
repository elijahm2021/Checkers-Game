#include "Checkers.h"

// function is used for testing faster by typing inputs straight into 
bool isArgument(int argc, char *arr[]);


int main(int argc, char *argv[]) {
    
    srand(time(0));
    Checkers gameBoard;
    
    string userInput;
    system("clear");
    
    // If there isn't anything after executable file
    if (!isArgument(argc, argv)) {
        cout << "Welcome to my checker game!" << endl << endl;
        cout << "Enter '1' for single player or '2' for two player or '3' to simulate: ";
    }
    else {
        userInput = argv[1];
    }
    
    
    do {
        if (!isArgument(argc, argv)) {
            cin >> userInput;
        }
        
        if (userInput == "1") {
            gameBoard.singlePlayer();
            break;
        }
        else if (userInput == "2") {
            gameBoard.twoPlayer();
            break;
        }
        else if (userInput == "3") {
            gameBoard.simulate();
            break;
        }
        else if (userInput == "4") {
            Checkers gameBoard(0);
            gameBoard.singlePlayer();
            break;
        }
        cout << endl;
        cout << "Please enter one of the three options ('1', '2', or '3') to play the game: ";
        
    } while (true);
    
    return 0;
}

// used when testing code to get through menu options faster
bool isArgument(int argc, char *argv[]) {
    if ((argc == 2) && (strcmp(argv[1], "1") == 0 || strcmp(argv[1], "2") == 0 || strcmp(argv[1], "3") == 0)) {
        return true;
    }
    return false;
}
