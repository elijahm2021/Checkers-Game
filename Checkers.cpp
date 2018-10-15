#include "Checkers.h"
#include "Piece.h"

// Main constructor
// Filling checker board and initialzing private member variables
Checkers::Checkers() {
    
    // Setting player one to be the first to move their piece
    playerOneTurn = true;
    
    // Initializing this variable to false for consecutive hops
    isConsecutiveHop = false;
    
    // Initializing this variable to false, but then setting to true if single player mode is selected
    // Used when determining the pause time in between turns for['']
    isSinglePlayer = false;
    
    // These two variables control the gameplay speed when simulation mode is selected
    // sleepTime decreases as the game goes on which speeds up the simulation game
    sleepTime = 500;
    // moveTime controls the rate at which sleepTime decreases
    moveTime = 0;
    
    // iterates through the 2D array to fill each spot in the array with a Piece object that hold empty Pieces
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = Piece(NONE, i, j);
        }
    }
    
    // Initializing black pieces in the coordinates of 2D array
    board[0][0] = Piece(BLACKNORMAL, 0, 0);
    board[1][1] = Piece(BLACKNORMAL, 1, 1);
    board[2][0] = Piece(BLACKNORMAL, 2, 0);
    board[0][2] = Piece(BLACKNORMAL, 0, 2);
    board[2][2] = Piece(BLACKNORMAL, 2, 2);
    board[1][3] = Piece(BLACKNORMAL, 1, 3);
    board[0][4] = Piece(BLACKNORMAL, 0, 4);
    board[2][4] = Piece(BLACKNORMAL, 2, 4);
    board[1][5] = Piece(BLACKNORMAL, 1, 5);
    board[0][6] = Piece(BLACKNORMAL, 0, 6);
    board[2][6] = Piece(BLACKNORMAL, 2, 6);
    board[1][7] = Piece(BLACKNORMAL, 1, 7);
    
    // Initializing red pieces in the coordinates of 2D array
    board[6][0] = Piece(REDNORMAL, 6, 0);
    board[5][1] = Piece(REDNORMAL, 5, 1);
    board[7][1] = Piece(REDNORMAL, 7, 1);
    board[6][2] = Piece(REDNORMAL, 6, 2);
    board[5][3] = Piece(REDNORMAL, 5, 3);
    board[7][3] = Piece(REDNORMAL, 7, 3);
    board[6][4] = Piece(REDNORMAL, 6, 4);
    board[5][5] = Piece(REDNORMAL, 5, 5);
    board[7][5] = Piece(REDNORMAL, 7, 5);
    board[6][6] = Piece(REDNORMAL, 6, 6);
    board[5][7] = Piece(REDNORMAL, 5, 7);
    board[7][7] = Piece(REDNORMAL, 7, 7);
}

// Test Constructor
// Filling checker board and initializing private member variables
Checkers::Checkers(int t) {
    
    // Included this if statement just because cloud 9 creates a warning error for the unused variable t
    if (t) {
        return;
    }

    // These two variables control the gameplay speed when simulation mode is selected
    // sleepTime decreases as the game goes on which speeds up the simulation game
    sleepTime = 3000;
    // moveTime controls the rate at which sleepTime decreases
    moveTime = 0;
       
    // Setting player one to be the first to move their piece
    playerOneTurn = true;
    
    // Initializing this variable to false for consecutive hops
    isConsecutiveHop = false;
    
    // Initializing this variable to false, but then setting to true if single player mode is selected
    isSinglePlayer = false;
    
    // iterates through the 2D array to fill each spot in the array with a Piece object that hold empty Pieces
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = Piece(NONE, i, j);
        }
    }
    
    // Initializing select black and red pieces in the coordinates of 2D array
    board[6][0] = Piece(REDKING, 6, 0);
    board[6][4] = Piece(REDKING, 6, 4);
    board[6][2] = Piece(REDKING, 6, 2);
    board[6][6] = Piece(REDKING, 6, 6);
    board[5][3] = Piece(BLACKNORMAL, 5, 3);
    board[5][5] = Piece(BLACKNORMAL, 5, 5);
    board[5][1] = Piece(BLACKNORMAL, 5, 1);
    board[3][3] = Piece(BLACKNORMAL, 3, 3);
    board[3][5] = Piece(BLACKNORMAL, 3, 5);
    board[3][1] = Piece(BLACKNORMAL, 3, 1);
}

// Draws the current stored checker board to the screen
void Checkers::drawBoard() const {
    
    // Clears the screen
    system("clear");
    
    // string variables uesd to help
    // Beginning space on the left side of the left boarder
    string begSpace = "        ";
    
    // Horizontal lines in between the checker pieces
    string rowSpacer = "----------------------------------------------";
    
    // The upper and lower horizontal boarder lines of the checker board
    string boarder = "----------------------------------------------------------------";
    
    // The space inside the checker board, but also above and below the outside alphabetical letters
    string sideToSide = "                                                              ";
    
    // It is begSpace on top of the left boarder line with another begSpace sized space
    string insideBegSpace = begSpace + '|' + begSpace;
    
    
    // Beginning of the function's output
    // Top part above the alphabetical letters of board
    cout << endl << endl;
    cout << begSpace << boarder << endl;
    cout << begSpace << '|' << sideToSide << '|' << endl;
    cout << begSpace << '|' << sideToSide << '|' << endl;
    cout << insideBegSpace << "     A    B    C    D    E    F    G    H     " << begSpace << '|' << endl;
    
    // Fills board using "board" private member 2D array variable to output the types of pieces in their correct positions
    // Basically builds the board without the spaces around the boarder
    for (int i = 8; i >= 1; --i) {
        cout << insideBegSpace << rowSpacer << begSpace << '|' << endl;
        cout << insideBegSpace << i << "   ";
        for (int j = 0; j < 8; ++j) {
            cout << "[" << board[abs(i-8)][j].pieceCharacter() << "]  ";
        }
        cout << " " << i << begSpace << '|' << endl;
    }
    
    // Below the functioning part of the board and draws the spaces and boarder below the board
    cout << insideBegSpace << rowSpacer << begSpace << '|' << endl;
    cout << insideBegSpace << "     A    B    C    D    E    F    G    H     " << begSpace << '|' << endl;
    cout << begSpace << '|' << sideToSide << '|' << endl;
    cout << begSpace << '|' << sideToSide << '|' << endl;
    cout << begSpace << boarder << endl;
    cout << endl << endl;
    
}

// Two player mode for checkers
void Checkers::twoPlayer() {

    // Loop breaks when a player has won
    while (true) {
        
        // Outputs board to screen using current 
        system("clear");
        drawBoard();
        
        if (playerOneTurn) {
            
            // Checks to see if all of player one's pieces are blocked
            if (noMove()) {
                cout << "All of player one's pieces are blocked." << endl << endl;
                cout << "Player two wins!" << endl << endl;
                cout << "Thanks for playing!" << endl << endl;
                return;
            }
            
            // Outputs player two's turn
            if (get<0>(prevMove) != "") {
                cout << "Player two moved from " << get<0>(prevMove) << " to " << get<1>(prevMove) << endl << endl;
            }
            
            cout << "Player one's turn" << endl << endl;
            
            choosePiece();
            chooseSpace();
            
            // Checks to see if player two's pieces are all gone
            if (endGame()) {
                
                drawBoard();
                cout << "Player one wins!" << endl << endl;
                cout << "Thanks for playing!" << endl << endl;
                return;
            }
            
            // Ends player one's turn
            playerOneTurn = false;
            
        }

        // Player two's turn
        else {
            
            // Checks to see if all of player two's pieces are blocked
            if (noMove()) {
                cout << "All of player two's pieces are blocked." << endl << endl;
                cout << "Player one wins!" << endl << endl;
                cout << "Thanks for playing!" << endl << endl;
                return;
            }
            
            // Outputs player one's previous move if there is one
            if (get<0>(prevMove) != "") {
                cout << "Player one moved from " << get<0>(prevMove) << " to " << get<1>(prevMove) << endl << endl;
            }
            
            cout << "Player two's turn" << endl << endl;
            choosePiece();
            chooseSpace();
            
            // Checks to see if player one's pieces are all gone
            if (endGame()) {
                drawBoard();
                cout << "Player two wins!" << endl << endl;
                cout << "Thanks for playing!" << endl << endl;
                return;
            }
            
            // Ends player two's turn
            playerOneTurn = true;
        }
    }

}

void Checkers::choosePiece() {
    
    // fills possible jumps into private member variable "redJumps" or "blackJumps"
    fillJumps();
    
    char whoseTurn = 'x';
    if (playerOneTurn) {
        whoseTurn = 'x';
    }
    else {
        whoseTurn = 'o';
    }
    
    // Checks to see if there are any possible jumps available to the current player's turn
    // redJumps and blackJumps are filled by having their first string in the inside vector being the checker piece to be moved 
    //     and the following string(s) being the string of coordinate(s) of where it can possibly move to
    if (playerOneTurn) { 
        
        if (redJumps.size() != 0) {
            
            cout << "You may only move the following pieces to its following coordinate(s)." << endl << endl; 
            
            for (unsigned i = 0; i < redJumps.size(); ++i) {
                cout << redJumps.at(i).getPosition() << " can move to spot(s): ";
                for (unsigned j = 0; j < redJumps.at(i).getJumps().size(); ++j) {
                    if (j == redJumps.at(i).getJumps().size() - 1) {
                        cout << redJumps.at(i).getJumps().at(j);
                        break;
                    }
                    cout << redJumps.at(i).getJumps().at(j) << " or ";
                }
                cout << endl << endl;
            }
        }
    }
    else {
        if (blackJumps.size() != 0) {
            
            cout << "You may only move the following pieces to its following coordinate(s)." << endl << endl; 
            
            for (unsigned i = 0; i < blackJumps.size(); ++i) {
                cout << blackJumps.at(i).getPosition() << " can move to spot(s): ";
                for (unsigned j = 0; j < blackJumps.at(i).getJumps().size(); ++j) {
                    if (j == blackJumps.at(i).getJumps().size() - 1) {
                        cout << blackJumps.at(i).getJumps().at(j);
                        break;
                    }
                    cout << blackJumps.at(i).getJumps().at(j) << " or ";
                }
                cout << endl << endl;
            }
        }
    }
    
    // Continues loop if input doesn't follow game rules or invalid input
    // Loop takes in user input as the piece they would want to move
    do {
        cout << "Enter the coordinates of the '" << whoseTurn << "' piece you would like to move (-999 to end the game): ";
        cin >> userInput;
        cout << endl;
        if (userInput == "-999") {
            cout << "Thanks for playing!" << endl << endl;
            exit(0);
        }
        if (!isValidInput()) {
            cout << "The coordinate format is a number(1-8) with a letter(A-H)." << endl << endl;
            continue;
        }
        
        // Takes private member variable "userInput" and converts the string into two the two private member integers: "curRow" and "curColumn"
        convertStringToCoordinate(curRow, curColumn);
        
        // Converts the coordinates back into a string so that "userInput" follows the format of one uppercase letter then one number
        // Example: If the user entered "5e", "userInput" would be converted to "E5"
        userInput = convertCoordinateToString(curRow, curColumn);
        
        if (playerOneTurn) {
            if (!(isRedPiece(curRow, curColumn))) {
                if (isBlackPiece(curRow, curColumn)) {
                    cout << "You chose the enemy's piece. Your pieces are the " << whoseTurn << "'s. Try again." << endl << endl;
                    continue;
                }
                else if (isInvalidSpace(curRow, curColumn)) {
                    cout << "You chose an invalid coordinate that isn't a part of the game. Try again." << endl << endl;
                    continue;
                }
                else {
                    cout << "This coordinate does not have your piece. Try again." << endl << endl;
                    continue;
                }
            }
        }
        else {
            if (!(isBlackPiece(curRow, curColumn))) {
                if (isRedPiece(curRow, curColumn)) {
                    cout << "You chose the enemy's piece. Your pieces are the " << whoseTurn << "'s. Try again." << endl << endl;
                    continue;
                }
                else if (isInvalidSpace(curRow, curColumn)) {
                    cout << "You chose an invalid coordinate that isn't a part of the game. Try again." << endl << endl;
                    continue;
                }
                else {
                    cout << "This coordinate does not have your piece. Try again." << endl << endl;
                    continue;
                }
            }
        }
        
        // The "chosePotentialJump" is used the check if the user chose a potential jump or not
        bool chosePotentialJump = false;
        
        if (playerOneTurn) {
            // Checking if user input matches one of player one's potential jumps
            if (redJumps.size() != 0) {
                for (unsigned i = 0; i < redJumps.size(); ++i) {
                    if (userInput == redJumps.at(i).getPosition()) {
                        chosePotentialJump = true;
                        break;
                    }
                }
                if (!chosePotentialJump) {
                    cout << "You must choose one of the above pieces that has a potential jump. Try again." << endl << endl;
                    continue;
                }
            }
            else {
                if (canNotMove(curRow, curColumn)) {
                    cout << "The piece at " << convertCoordinateToString(curRow, curColumn)  << " has no possible spots that it can move to. Try again." << endl << endl;
                    continue;
                }
            }
            // Sets private member variable pair type prevMove's first place the current checker piece selected
            get<0>(prevMove) = convertCoordinateToString(curRow, curColumn);
            break;
        }
        else {
            // Checking if user input matches one of player two's potential jumps
            if (blackJumps.size() != 0) {
                for (unsigned i = 0; i < blackJumps.size(); ++i) {
                    if (userInput == blackJumps.at(i).getPosition()) {
                        chosePotentialJump = true;
                        break;
                    }
                }
                if (!chosePotentialJump) {
                    cout << "You must choose one of the above pieces that has a potential jump. Try again." << endl << endl;
                    continue;
                }
            }
            else {
                if (canNotMove(curRow, curColumn)) {
                    cout << "The piece at " << convertCoordinateToString(curRow, curColumn)  << " has no possible spots that it can move to. Try again." << endl << endl;
                    continue;
                }
            }
            // Sets private member variable pair type prevMove's first place the current checker piece selected
            get<0>(prevMove) = convertCoordinateToString(curRow, curColumn);
            break;
        }
        
    }
    while (true);
    
}

void Checkers::chooseSpace() {
    
    do {
        // If another move is possible
        if (isConsecutiveHop) {
            drawBoard(); 
            
            // Outputs possible checkers that can be moved and where they can be moved to
            // see how redJumps and blackJumps are filled in the Checkers.h file
            if (playerOneTurn) {
                cout << "Player one's turn" << endl << endl;
                cout << redJumps.at(0).getPosition() << " can move to spot(s): ";
                for (unsigned j = 0; j < redJumps.at(0).getJumps().size(); ++j) {
                    if (j == redJumps.at(0).getJumps().size() - 1) {
                        cout << redJumps.at(0).getJumps().at(j);
                        break;
                    }
                    cout << redJumps.at(0).getJumps().at(j) << " or ";
                }
                cout << endl << endl;
            
            }
            else {
                cout << "Player two's turn" << endl << endl;
                cout << blackJumps.at(0).getPosition() << " can move to spot(s): ";
                for (unsigned j = 0; j < blackJumps.at(0).getJumps().size(); ++j) {
                    if (j == blackJumps.at(0).getJumps().size() - 1) {
                        cout << blackJumps.at(0).getJumps().at(j);
                        break;
                    }
                    cout << blackJumps.at(0).getJumps().at(j) << " or ";
                }
                cout << endl << endl;
                
            }
        }
        // End of if (isConsecutiveHop) {}
        
        
        cout << "Enter the coordinates of where you want to move piece " << convertCoordinateToString(curRow, curColumn) << " (-999 to end the game)";
        if (isConsecutiveHop) {
            cout << endl << endl << "You may enter 'end' to end you turn: ";
        }
        else {
            cout << ": ";
        }
        cin >> userInput;
        cout << endl;
        
        if (userInput == "-999") {
            cout << "Thanks for playing!" << endl << endl;
            exit(0);
        }
        else if (userInput == "end") {
            get<1>(prevMove) = convertCoordinateToString(newRow, newColumn);
            return;
        }
        if (!(isValidInput())) {
            cout << "The coordinate format is a number(1-8) with a letter(A-H)." << endl << endl;;
            continue;
        }
        
        convertStringToCoordinate(newRow, newColumn);
        
        // These variables are used to just check that if there is a potential jump then the user must make a potential jump
        bool redHop = false;
        bool blackHop = false;

        // traverses through each checker piece in redJumps and checks to see if the user's choice matches one of the piece's possible jumps from redJumps
        int counter = 0; 
        if (playerOneTurn) { 
            for (unsigned i = 0; i < redJumps.size(); ++i) {
                redHop = true;
                if (convertCoordinateToString(curRow, curColumn) == redJumps.at(i).getPosition()) {
                    for (unsigned j = 0; j < redJumps.at(i).getJumps().size(); ++j) {
                        if (convertCoordinateToString(newRow, newColumn) == redJumps.at(i).getJumps().at(j)) {
                            ++counter;
                            movePiece();
                            break;
                        }
                        
                    }
                }
            }
            if (counter == 0 && redHop) {
                cout << "You must choose one of the above coordinates to move the piece " << convertCoordinateToString(curRow, curColumn) << " to. Try again." << endl << endl;
            }
            else if (counter != 0 && redHop) {
                break;
            }
        }
        // traverses through each checker piece in blackJumps and checks to see if the user's choice matches one of the piece's possible jumps from blackJumps
        else {
            for (unsigned i = 0; i < blackJumps.size(); ++i) {
                blackHop = true;
                if (convertCoordinateToString(curRow, curColumn) == blackJumps.at(i).getPosition()) {
                    for (unsigned j = 0; j < blackJumps.at(i).getJumps().size(); ++j) {
                        if (convertCoordinateToString(newRow, newColumn) == blackJumps.at(i).getJumps().at(j)) {
                            ++counter;
                            movePiece();
                            break;
                        }
                    }
                }
            }
            if (counter == 0 && blackHop) {
                cout << "You must choose one of the above coordinates to move the piece " << convertCoordinateToString(curRow, curColumn) << " to. Try again." << endl << endl;
            }
            else if (counter != 0 && blackHop) {
                break;
            }
        }
        
        
        if (isInvalidSpace(newRow, newColumn)) {
            cout << "You chose an invalid coordinate that isn't a part of the game. Try again." << endl << endl;
            continue;
        }
        if (isSpaceFilled()) {
            cout << "You must choose an empty space to move your checker piece. Try again." << endl << endl;
            continue;
        }
        if (!isValidMove()) {
            cout << "You cannot move piece " << convertCoordinateToString(curRow, curColumn) << " to coordinate " << convertCoordinateToString(newRow, newColumn) << ". Try again. " << endl << endl;
            continue;
        }
        
        movePiece();
        
        break;
    }
    while (true);
}

void Checkers::movePiece() {
    
    isConsecutiveHop = false;
    
    // Checking to see if the selected checker piece is making a jump
    if (newRow == curRow + 2 || newRow == curRow - 2) {
        
        // Moving the checker piece
        board[newRow][newColumn].newType(board[curRow][curColumn].getType());
        
        // Making the piece jumped an empty space
        board[curRow][curColumn].newType(NONE);
        board[(newRow+curRow)/2][(newColumn+curColumn)/2].newType(NONE);
        
        // makes piece king if needed
        makeKing();
        
        // Empties vectors to fill it again if there is another jump available
        emptyJumps();
        emptyPieces();
        
        if (anotherJump(newRow, newColumn)) {
            
            isConsecutiveHop = true;
            curRow = newRow;
            curColumn = newColumn;
            chooseSpace();
        }
    }
    else {
        // Moving the checker piece
        board[newRow][newColumn].newType(board[curRow][curColumn].getType());
        board[curRow][curColumn].newType(NONE);
        
        // makes piece king if needed
        makeKing();
    }
    if (isConsecutiveHop == false) {
        // Since there isn't another hop, prevMove final position is set to newRow and newColumn to be displayed to the opponent
        get<1>(prevMove) = convertCoordinateToString(newRow, newColumn);
    }
}

// Checking if the checker space is filled with a checker piece or not
bool Checkers::isSpaceFilled() const{
    if (!(isNoPiece(newRow, newColumn))) {
        return true;
    }
    return false;
}

// Checking to see if the chosen space is a valid move for the selected checker piece
bool Checkers::isValidMove() const{
    if (isKing(curRow, curColumn)) {
        if ((newRow == (curRow - 1)) && (newColumn == (curColumn - 1))) {
            return true;
        }
        else if ((newRow == (curRow - 1)) && (newColumn == (curColumn + 1))) {
            return true;
        }
        else if ((newRow == (curRow + 1)) && (newColumn == (curColumn - 1))) {
            return true;
        }
        else if ((newRow == (curRow + 1)) && (newColumn == (curColumn + 1))) {
            return true;
        }
    }
    else if (isRedNormal(curRow, curColumn)) {
        if ((newRow == (curRow - 1)) && (newColumn == (curColumn - 1))) {
            return true;
        }
        else if ((newRow == (curRow - 1)) && (newColumn == (curColumn + 1))) {
            return true;
        }
    }
    else {
        if ((newRow == (curRow + 1)) && (newColumn == (curColumn - 1))) {
            return true;
        }
        else if ((newRow == (curRow + 1)) && (newColumn == (curColumn + 1))) {
            return true;
        }
    }
    return false;
}

// Checking to see if the chosen space is a part of the correct diagnol lines of the game
bool Checkers::isInvalidSpace(int row, int column) const{
    if      (row == 0 && column == 1) {return true;}
    else if (row == 0 && column == 3) {return true;}
    else if (row == 0 && column == 5) {return true;}
    else if (row == 0 && column == 7) {return true;}
    else if (row == 1 && column == 0) {return true;}
    else if (row == 1 && column == 2) {return true;}
    else if (row == 1 && column == 4) {return true;}
    else if (row == 1 && column == 6) {return true;}
    else if (row == 2 && column == 1) {return true;}
    else if (row == 2 && column == 3) {return true;}
    else if (row == 2 && column == 5) {return true;}
    else if (row == 2 && column == 7) {return true;}
    else if (row == 3 && column == 0) {return true;}
    else if (row == 3 && column == 2) {return true;}
    else if (row == 3 && column == 4) {return true;}
    else if (row == 3 && column == 6) {return true;}
    else if (row == 4 && column == 1) {return true;}
    else if (row == 4 && column == 3) {return true;}
    else if (row == 4 && column == 5) {return true;}
    else if (row == 4 && column == 7) {return true;}
    else if (row == 5 && column == 0) {return true;}
    else if (row == 5 && column == 2) {return true;}
    else if (row == 5 && column == 4) {return true;}
    else if (row == 5 && column == 6) {return true;}
    else if (row == 6 && column == 1) {return true;}
    else if (row == 6 && column == 3) {return true;}
    else if (row == 6 && column == 5) {return true;}
    else if (row == 6 && column == 7) {return true;}
    else if (row == 7 && column == 0) {return true;}
    else if (row == 7 && column == 2) {return true;}
    else if (row == 7 && column == 4) {return true;}
    else if (row == 7 && column == 6) {return true;}

    return false;
}

// Checking to see if the input follows the input guidelines of one number and one letter that is an existing coordinate a part of the game
bool Checkers::isValidInput() const{
    
    // Has to be two characters
    if (userInput.size() != 2) {
        return false;
    }
    
    // If it is not two characters that are either a number and a letter or a letter and a number
    if (!((isalpha(userInput.at(0)) && isdigit(userInput.at(1))) || (isdigit(userInput.at(0)) && isalpha(userInput.at(1))))) {
        return false;
    }
    
    // Specifies what problem the user made
    if (isalpha(userInput.at(0))) {
        if ((userInput.at(0) > 72 && userInput.at(0) < 91) || (userInput.at(0) > 104)) {
            cout << "The letter must be between A and H" << endl;
            return false;
        }
        else if (userInput.at(1) < 49 || userInput.at(1) > 56) {
            cout << "The number must be between 1 and 8" << endl;
            return false;
        }
    }
    
    // Specifies what problem the user made
    else if (isalpha(userInput.at(1))) {
        if ((userInput.at(1) > 72 && userInput.at(1) < 91) || (userInput.at(1) > 104)) {
            cout << "The letter must be within the letters (A-H)" << endl;
            return false;
        }
        else if (userInput.at(0) < 49 || userInput.at(0) > 56) {
            cout << "The number must be between 1 and 8" << endl;
            return false;
        }
    }
    return true;
}

// Checks to see the game ended by seeing if any player's pieces are completely off the board
bool Checkers::endGame() const{
    int xCounter = 0, oCounter = 0;

    for (unsigned i = 0; i < 8; ++i) {
        for (unsigned j = 0; j < 8; ++j) {
            if (isRedPiece(i, j)) {
                ++xCounter;
            }
            else if (isBlackPiece(i, j)) {
                ++oCounter;
            }
        }
    }
    if (xCounter == 0 || oCounter == 0) {
        return true;
    }
    return false;
}


bool Checkers::canNotMove(int row, int column) const{
    
    // Checking to see if the king cannot move on all four sides
    if (isKing(row, column)) {
        if (row == 0) {
            if (column == 0 && !(isNoPiece(1,1))) {
                return true;
            }
            else if (column != 0 && !(isNoPiece(row+1,column+1)) && !(isNoPiece(row+1,column-1))) {
                return true;
            }
        }
        else if (row == 7) {
            if (column == 7 && !(isNoPiece(6,6))) {
                return true;
            }
            else if (column != 7 && !(isNoPiece(row-1,column+1)) && !(isNoPiece(row-1,column-1))) {
                return true;
            }
            
        }
        else {
            if (column == 0 && row != 0) {
                if (!(isNoPiece(row+1,column+1)) && !(isNoPiece(row-1,column+1))) {
                    return true;
                }
            }
            else if (column == 7 && row != 7) {
                if (!(isNoPiece(row+1,column-1)) && !(isNoPiece(row-1,column-1))) {
                    return true;
                }
            }
            else {
                if (!(isNoPiece(row+1,column+1)) && !(isNoPiece(row-1,column+1)) && !(isNoPiece(row+1,column-1)) && !(isNoPiece(row-1,column-1))) {
                    return true;
                }
            }
        }
    }
    // Checks to see if a regular red piece is blocked on its forward two sides
    else if (isRedNormal(row, column)) {
        if (column == 0) {
            if (!(isNoPiece(row-1,column+1))) {
                return true;
            }
        }
        else if (column == 7) {
            if (!(isNoPiece(row-1,column-1))) {
                return true;
            }
        }
        else {
            if (!(isNoPiece(row-1,column-1)) && !(isNoPiece(row-1,column+1))) {
                return true;
            }
        }
    }
        
    // Checks to see if a regular black piece is blocked on its forward two sides
    else {
        if (column == 0) {
            if (!(isNoPiece(row+1,column+1))) {
                return true;
            }
        }
        else if (column == 7) {
            if (!(isNoPiece(row+1,column-1))) {
                return true;
            }
        }
        else {
            if (!(isNoPiece(row+1,column-1)) && !(isNoPiece(row+1,column+1))) {
                return true;
            }
        }
    }
    return false;
}


bool Checkers::noMove() {
    
    fillJumps();
    
    int immovablePieces = 0;
    int pieces = 0;
    
    
    if (playerOneTurn) {

        if (redJumps.size() != 0) {
            return false;
        }
        // Iterates through board and increments immovable pieces if it cant move
        for (unsigned i = 0; i < 8; ++i) {
            for (unsigned j = 0; j < 8; ++j) {
                if (isRedPiece(i,j)) {
                    ++pieces;
                    if (canNotMove(i,j)) {
                        ++immovablePieces;
                    }
                }
            }
        }
    }
    
    else {
        
        if (blackJumps.size() != 0) {
            return false;
        }
        // Iterates through board and increments immovable pieces if it cant move
        for (unsigned i = 0; i < 8; ++i) {
            for (unsigned j = 0; j < 8; ++j) {
                if (isBlackPiece(i,j)) {
                    ++pieces;
                    if (canNotMove(i,j)) {
                        ++immovablePieces;
                    }
                }
            }
        }
    }
    // Checks to see if total amount of pieces the player has is equal to the amount of 
    if (pieces == immovablePieces) {
        return true;
    }
    return false;
}


//checks if the space passed in holds a red piece or red king
bool Checkers::isRedPiece(int row, int column) const{
    if (board[row][column].getType() == REDNORMAL || board[row][column].getType() == REDKING) {
        return true;
    }
    return false;
}

//checks if the space passed in holds a black piece or black king
bool Checkers::isBlackPiece(int row, int column) const{
    if (board[row][column].getType() == BLACKNORMAL || board[row][column].getType() == BLACKKING) {
        return true;
    }
    return false;
}

//checks if the space passed in contains no piece
bool Checkers::isNoPiece(int row, int column) const{
    if (board[row][column].getType() == NONE) {
        return true;
    }
    return false;
}

//checks if space passed in is specifically a red king
bool Checkers::isRedKing(int row, int column) const{
    if (board[row][column].getType() == REDKING) {
        return true;
    }
    return false;
}

//checks if space passed in is specifically a black king
bool Checkers::isBlackKing(int row, int column) const{
    if (board[row][column].getType() == BLACKKING) {
        return true;
    }
    return false;
}

//returns true if piece can make another jump
bool Checkers::anotherJump(int row, int column) {
    int redCounter = 0;
    int blackCounter = 0;
    
    //makes sure the piece wont jump off the board
    if (row >= 2 && column >= 2) {
        //checks if space has a red piece and can jump a black piece to its upper left
        if (isRedPiece(row, column) && isBlackPiece(row-1, column-1) && isNoPiece(row-2,column-2)) {
            board[row][column].pushJump(row-2,column-2);
            redJumps.push_back(board[row][column]);
            ++redCounter;
        }
        //checks if space contains a black king and can jump a red piece to its upper left
        if (isBlackKing(row, column) && isRedPiece(row-1, column-1) && isNoPiece(row-2,column-2)) {
            board[row][column].pushJump(row-2,column-2);
            blackJumps.push_back(board[row][column]);
            ++blackCounter;
        }
    }
    //makes sure piece won't jump off board
    if (row >= 2 && column <= 5) {
        //checks if space has a red piece and can jump a black piece to its upper right
        if (isRedPiece(row, column) && isBlackPiece(row-1, column+1) && isNoPiece(row-2,column+2)) {
            board[row][column].pushJump(row-2,column+2);
            if (redCounter == 0) {
                redJumps.push_back(board[row][column]);
            }
            else {
                redJumps.pop_back();
                redJumps.push_back(board[row][column]);
            }
               ++redCounter;
           }
        //checks if space has a black king and can jump a red piece to its upper right
        if (isBlackKing(row, column) && isRedPiece(row-1, column+1) && isNoPiece(row-2,column+2)) {
            board[row][column].pushJump(row-2,column+2);
            if (blackCounter == 0) {
                blackJumps.push_back(board[row][column]);
            }
            else {
                blackJumps.pop_back();
                blackJumps.push_back(board[row][column]);
            }
            ++blackCounter;
        }
    }
    //makes sure piece wont jump off board
    if (row <= 5 && column >= 2) {
        //checks if space has a black piece and can jump a red piece to its lower left
        if (isBlackPiece(row, column) && isRedPiece(row+1, column-1) && isNoPiece(row+2,column-2)) {
            board[row][column].pushJump(row+2,column-2);
            if (blackCounter == 0) {
                blackJumps.push_back(board[row][column]);
            }
            else {
                blackJumps.pop_back();
                blackJumps.push_back(board[row][column]);
            }
            ++blackCounter;
        }
            //checks if space has a red king and can jump a red piece to its lower left
            if (isRedKing(row, column) && isBlackPiece(row+1, column-1) && isNoPiece(row+2,column-2)) {
            board[row][column].pushJump(row+2,column-2);
            if (redCounter == 0) {
                redJumps.push_back(board[row][column]);
                }
            else {
                redJumps.pop_back();
                    redJumps.push_back(board[row][column]);
            }
                ++redCounter;
        }
    }
    //makes sure piece cant jump off board
    if (row <= 5 && column <= 5) {
        //checks if space has a black piece and can jump a red piece to its lower right
        if (isBlackPiece(row, column) && isRedPiece(row+1, column+1) && isNoPiece(row+2,column+2)) {
            board[row][column].pushJump(row+2,column+2);
            if (blackCounter == 0) {
                blackJumps.push_back(board[row][column]);
            }
            else {
                blackJumps.pop_back();
                blackJumps.push_back(board[row][column]);
            }
            ++blackCounter;
        }
        //checks if space has a red king and can jump a black piece to its lower right
        if (isRedKing(row, column) && isBlackPiece(row+1, column+1) && isNoPiece(row+2,column+2)) {
            board[row][column].pushJump(row+2,column+2);
            if (redCounter == 0) {
                redJumps.push_back(board[row][column]);
            }
            else {
                redJumps.pop_back();
                redJumps.push_back(board[row][column]);
            }
            ++redCounter;
        }
    }
    if (redCounter || blackCounter) {
        return true;
    }
    return false;
}

//returns true if space contains a red piece that is not a king
bool Checkers::isRedNormal(int row, int column) const{
    if (board[row][column].getType() == REDNORMAL) {
        return true;
    }
    return false;
}

//returns true if space contains a red piece that is not a king
bool Checkers::isBlackNormal(int row, int column) const{
    if (board[row][column].getType() == BLACKNORMAL) {
        return true;
    }
    return false;
}

//returns if piece is either a red or black king
bool Checkers::isKing(int row, int column) const{
    if (board[row][column].getType() == REDKING || board[row][column].getType() == BLACKKING) {
        return true;
    }
    return false;
}

//returns is piece is red or black but not a king
bool Checkers::isNormal(int row, int column) const{
    if (board[row][column].getType() == REDNORMAL || board[row][column].getType() == BLACKNORMAL) {
        return true;
    }
    return false;
}

//filling vector with all possibilities to jump another piece
void Checkers::fillJumps() {
    emptyJumps();
    emptyPieces();
    int blackCounter = 0;
    int redCounter = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {

            redCounter = 0;
            blackCounter = 0;
            
            //cant jump off the board
            if (i >= 2 && j >= 2) {
                //checks if red piece can jump a black piece to the upper left
                if (isRedPiece(i, j) && isBlackPiece(i-1, j-1) && isNoPiece(i-2,j-2)) {
                    board[i][j].pushJump(i-2,j-2);
                    redJumps.push_back(board[i][j]);
                    ++redCounter;
                }
                //checks if black king can jump a red piece to its upper left
                if (isBlackKing(i,j) && isRedPiece(i-1, j-1) && isNoPiece(i-2,j-2)){
                    board[i][j].pushJump(i-2,j-2);
                    blackJumps.push_back(board[i][j]);
                    ++blackCounter;
                }
            }
            if (i >= 2 && j <= 5) {
                //checks if a red piece can jump a black piece to its upper right
                if (isRedPiece(i, j) && isBlackPiece(i-1, j+1) && isNoPiece(i-2,j+2)) {
                    board[i][j].pushJump(i-2,j+2);
                    if (redCounter == 0) {
                        redJumps.push_back(board[i][j]);
                        
                    }
                    else {
                        redJumps.pop_back();
                        redJumps.push_back(board[i][j]);
                    }
                    ++redCounter;
                }
                //checks if black king can jump a red piece to its upper left
                if (isBlackKing(i,j) && isRedPiece(i-1, j+1) && isNoPiece(i-2,j+2)) {
                    board[i][j].pushJump(i-2,j+2);
                    if (blackCounter == 0) {
                        blackJumps.push_back(board[i][j]);
                    }
                    else {
                        blackJumps.pop_back();
                        blackJumps.push_back(board[i][j]);
                    }
                    ++blackCounter;
                }
            }
            if (i <= 5 && j >= 2) {
                //checks if black piece can jump a red piece to its lower left
                if (isBlackPiece(i, j) && isRedPiece(i+1, j-1) && isNoPiece(i+2,j-2)) {
                    board[i][j].pushJump(i+2,j-2);
                    if (blackCounter == 0) {
                        blackJumps.push_back(board[i][j]);
                    }
                    else {
                        blackJumps.pop_back();
                        blackJumps.push_back(board[i][j]);
                    }
                    ++blackCounter;
                }
                //checks if red king can jump a black piece to its lower left
                if (isRedKing(i,j) && isBlackPiece(i+1, j-1) && isNoPiece(i+2,j-2)) {
                    board[i][j].pushJump(i+2,j-2);
                    if (redCounter == 0) {
                        redJumps.push_back(board[i][j]);
                    }
                    else {
                        redJumps.pop_back();
                        redJumps.push_back(board[i][j]);
                    }
                    ++redCounter;
                }
            }
            if (i <= 5 && j <= 5) {
                //checks if black piece can jump red piece to its lower right
                if (isBlackPiece(i, j) && isRedPiece(i+1, j+1) && isNoPiece(i+2,j+2)) {
                    board[i][j].pushJump(i+2,j+2);
                    if (blackCounter == 0) {
                        blackJumps.push_back(board[i][j]);
                    }
                    else {
                        blackJumps.pop_back();
                        blackJumps.push_back(board[i][j]);
                    }
                    ++blackCounter;
                }
                //checks if red king can jump a black piece to its lower right
                if (isRedKing(i,j) && isBlackPiece(i+1, j+1) && isNoPiece(i+2,j+2)) {
                    board[i][j].pushJump(i+2,j+2);
                    if (redCounter == 0) {
                        redJumps.push_back(board[i][j]);
                    }
                    else {
                        redJumps.pop_back();
                        redJumps.push_back(board[i][j]);
                    }
                    ++redCounter;
                }
            }
            
            
            
        }
    }
    
}

//iterates through every piece on the board and clears any jumps stored
void Checkers::emptyJumps() {
    for (unsigned i = 0; i < 8; ++i) {
        for (unsigned j = 0; j < 8; ++j) {
            board[i][j].clearJumps();
        }
    }
}

//empties vectors redJumps and blackJumps
void Checkers::emptyPieces() {
    redJumps.clear();
    blackJumps.clear();
}


void Checkers::convertStringToCoordinate(int &row, int &column) {
    if ((userInput.at(0) == 'a' || userInput.at(0) == 'A') || (userInput.at(1) == 'a' || userInput.at(1) == 'A')){
        column = 0;
    }
    else if ((userInput.at(0) == 'b' || userInput.at(0) == 'B') || (userInput.at(1) == 'b' || userInput.at(1) == 'B')){
        column = 1;
    }
    else if ((userInput.at(0) == 'c' || userInput.at(0) == 'C') || (userInput.at(1) == 'c' || userInput.at(1) == 'C')){
        column = 2;
    }
    else if ((userInput.at(0) == 'd' || userInput.at(0) == 'D') || (userInput.at(1) == 'd' || userInput.at(1) == 'D')){
        column = 3;
    }
    else if ((userInput.at(0) == 'e' || userInput.at(0) == 'E') || (userInput.at(1) == 'e' || userInput.at(1) == 'E')){
        column = 4;
    }
    else if ((userInput.at(0) == 'f' || userInput.at(0) == 'F') || (userInput.at(1) == 'f' || userInput.at(1) == 'F')){
        column = 5;
    }
    else if ((userInput.at(0) == 'g' || userInput.at(0) == 'G') || (userInput.at(1) == 'g' || userInput.at(1) == 'G')){
        column = 6;
    }
    else if ((userInput.at(0) == 'h' || userInput.at(0) == 'H') || (userInput.at(1) == 'h' || userInput.at(1) == 'H')){
        column = 7;
    }
    if ((userInput.at(0) == '1') || (userInput.at(1) == '1')){
        row = 0;
    }
    else if ((userInput.at(0) == '2') || (userInput.at(1) == '2')){
        row = 1;
    }
    else if ((userInput.at(0) == '3') || (userInput.at(1) == '3')){
        row = 2;
    }
    else if ((userInput.at(0) == '4') || (userInput.at(1) == '4')){
        row = 3;
    }
    else if ((userInput.at(0) == '5') || (userInput.at(1) == '5')){
        row = 4;
    }
    else if ((userInput.at(0) == '6') || (userInput.at(1) == '6')){
        row = 5;
    }
    else if ((userInput.at(0) == '7') || (userInput.at(1) == '7')){
        row = 6;
    }
    else if ((userInput.at(0) == '8') || (userInput.at(1) == '8')){
        row = 7;
    }
    
    row = abs(row - 7);
}

// turns the coordinate into a string that follows a number and a letter format EX. 4C
string Checkers::convertCoordinateToString(int row, int column) {
    row = abs(row - 8);
    char columnChar = 'A' + column; 
    string returnString;
    returnString = to_string(row) + columnChar;
    return returnString;
}

// turns a normal piece into a king
void Checkers::makeKing() {
    if (newRow == 0 && isRedNormal(newRow, newColumn)) {
        board[newRow][newColumn].newType(REDKING);
    }
    if (newRow == 7 && isBlackNormal(newRow, newColumn)) {
        board[newRow][newColumn].newType(BLACKKING);
    }
}