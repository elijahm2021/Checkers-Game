#include "Checkers.h"

void Checkers::simulate() {
    //continues to simulate game until false
    while (true) {
        system("clear");
        drawBoard();
        if (playerOneTurn) {
            //player 2 wins if player 1 has no more moves
            if (noMove()) {
                cout << "All of player one's pieces are blocked." << endl << endl;
                cout << "Player two wins!" << endl << endl;
                cout << "Thanks for playing!" << endl << endl;
                return;
            }
            //outputs the previous move
            if (get<0>(prevMove) != "") {
                cout << "Player two moved from " << get<0>(prevMove) << " to " << get<1>(prevMove) << endl << endl;
            }
            cout << "Player one's turn" << endl << endl;
            
            simChoosePieceRand();
            
            //outputs winning message
            if (endGame()) {
                drawBoard();
                cout << "Player one wins!" << endl << endl;
                cout << "Thanks for playing!" << endl << endl;
                return;
            }
            playerOneTurn = false;
        }
        else {
            //checks if player two cannot make any more moves
            if (noMove()) {
                cout << "All of player two's pieces are blocked." << endl << endl;
                cout << "Player one wins!" << endl << endl;
                cout << "Thanks for playing!" << endl << endl;
                return;
            }
            //outputs previosu move
            if (get<0>(prevMove) != "") {
                cout << "Player one moved from " << get<0>(prevMove) << " to " << get<1>(prevMove) << endl << endl;
            }
            cout << "Player two's turn" << endl << endl;
            simChoosePieceRand();
            
            //outputs winning message
            if (endGame()) {
                drawBoard();
                cout << "Player two wins!" << endl << endl;
                cout << "Thanks for playing!" << endl << endl;
                return;
            }
            playerOneTurn = true;
        }
    }

}

// chooses a random piece from possible moves available
void Checkers::simChoosePieceRand() {
    fillJumps();
    
    vector<string> temp;
    char whosTurn = 'x';
    
    if (!playerOneTurn) {
        whosTurn = 'o';
    }

    if (playerOneTurn) {
        if (redJumps.size() != 0) {
            
            cout << "You may only move the following pieces to its following coordinate(s)." << endl << endl; 
            
            // iterates through "redJumps" and through "jumps" to output what available checker pieces player one can move to
            for (unsigned i = 0; i < redJumps.size(); ++i) {
                
                cout << redJumps.at(i).getPosition() << " can move to spot(s): ";
                for (unsigned j = 0; j < redJumps.at(i).getJumps().size(); ++j) {
                    temp.push_back(redJumps.at(i).getPosition());
                    temp.push_back(redJumps.at(i).getJumps().at(j));
                    possibleMoves.push_back(temp);
                    temp.clear();
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
            
            // iterates through "blackJumps" and through "jumps" to output what available checker pieces player one can move to
            for (unsigned i = 0; i < blackJumps.size(); ++i) {
                cout << blackJumps.at(i).getPosition() << " can move to spot(s): ";
                for (unsigned j = 0; j < blackJumps.at(i).getJumps().size(); ++j) {
                    temp.push_back(blackJumps.at(i).getPosition());
                    temp.push_back(blackJumps.at(i).getJumps().at(j));
                    possibleMoves.push_back(temp);
                    temp.clear();
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
    
    if (possibleMoves.size() == 0) {
        fillPossibleMoves();
    }
    
    // creates a random position on the vector possibleMoves
    int possibleMovesPosition = rand() % possibleMoves.size();
    
    // string choice is what the random position of the possibleMoves vector that is the checker piece that is selected to move
    string choice = possibleMoves.at(possibleMovesPosition).at(0);
    userInput = choice;
    convertStringToCoordinate(curRow, curColumn);
    
    // sets previous move's starting position to this coordinate
    get<0>(prevMove) = convertCoordinateToString(curRow, curColumn);
    
    cout << "Enter the coordinates of the '" << whosTurn << "' piece you would like to move (-999 to end the game): ";
    cout << choice << endl << endl;
    
    // pauses program for a little amount of time to make AI seem more human
    pauseTime();
    
    // chooses space using this calculated position
    simChooseSpaceRand(possibleMovesPosition);
  
}

//takes coordinate and outputs its available move
void Checkers::simChooseSpaceRand(int possibleMovesPosition) {
    cout << "Enter the coordinates of where you want to move piece " << convertCoordinateToString(curRow, curColumn) << " (-999 to end the game): ";
    cout << possibleMoves.at(possibleMovesPosition).at(1) << endl << endl;
    
    pauseTime();
    
    userInput = possibleMoves.at(possibleMovesPosition).at(1); 
    convertStringToCoordinate(newRow, newColumn);
    
    simMovePiece();
    
    possibleMoves.clear();
}

// moves the selected piece to its selected position
void Checkers::simMovePiece() {
    
    isConsecutiveHop = false;
    
    // checks to see if the selected piece made a jump to its new position
    if (newRow == curRow + 2 || newRow == curRow - 2) {
        
        // moves the piece
        board[newRow][newColumn].newType(board[curRow][curColumn].getType());
        
        // removes jumped piece
        board[curRow][curColumn].newType(NONE);
        board[(newRow+curRow)/2][(newColumn+curColumn)/2].newType(NONE);
        
        // makes piece king if needed
        makeKing();
        
        emptyJumps();
        emptyPieces();
        
        // checks to see if another jump is available
        if (anotherJump(newRow, newColumn)) {
            
            // makes it a 90% chance for the AI to decide to make the jump or not
            int chance = (rand() % 10);
            if (chance != 9) {
                isConsecutiveHop = true;
                curRow = newRow;
                curColumn = newColumn;
                simChooseAnotherSpaceRand();
            }
        }
    }
    else {
        // moves piece
        board[newRow][newColumn].newType(board[curRow][curColumn].getType());
        board[curRow][curColumn].newType(NONE);
        
        //makes piece king if needed
        makeKing();
    }
    
    
    if (isConsecutiveHop == false) {
        get<1>(prevMove) = convertCoordinateToString(newRow, newColumn);
    }
    
}

void Checkers::simChooseAnotherSpaceRand() {
    
    char whosTurn = 'x';
    
    if (!playerOneTurn) {
        whosTurn = 'o';
    }
    
    possibleMoves.clear();
    drawBoard();
    vector<string> temp;
    if (playerOneTurn) {
        cout << endl << endl;
        cout << "Player one's turn" << endl << endl;
        cout << redJumps.at(0).getPosition() << " can move to spot(s): ";
        
        // iterates through the possible moves that player on can make by pushing temporary string vectors into the possibleMoves vector
        for (unsigned j = 0; j < redJumps.at(0).getJumps().size(); ++j) {
            temp.push_back(redJumps.at(0).getPosition());
            temp.push_back(redJumps.at(0).getJumps().at(j));
            possibleMoves.push_back(temp);
            temp.clear();
            if (j == redJumps.at(0).getJumps().size() - 1) {
                cout << redJumps.at(0).getJumps().at(j);
                break;
            }
            cout << redJumps.at(0).getJumps().at(j) << " or ";
        }
        cout << endl << endl;
    
    }
    else {
        cout << endl << endl << "Player two's turn";
        cout << endl << endl << blackJumps.at(0).getPosition() << " can move to spot(s): ";
        
        // iterates through the possible moves that player on can make by pushing temporary string vectors into the possibleMoves vector
        for (unsigned j = 0; j < blackJumps.at(0).getJumps().size(); ++j) {
            temp.push_back(blackJumps.at(0).getPosition());
            temp.push_back(blackJumps.at(0).getJumps().at(j));
            possibleMoves.push_back(temp);
            temp.clear();
            if (j == blackJumps.at(0).getJumps().size() - 1) {
                cout << blackJumps.at(0).getJumps().at(j);
                break;
            }
            cout << blackJumps.at(0).getJumps().at(j) << " or ";
        }
        cout << endl << endl;
    }
    
    // randomizes the integer position of possibleMoves vector.
    int possibleMovesPosition = rand() % possibleMoves.size();
    
    // choice is the string of the coordinates of the selected piece position
    string choice = possibleMoves.at(possibleMovesPosition).at(0);

    userInput = choice;
    convertStringToCoordinate(curRow, curColumn);
    
    

    cout << "Enter the coordinates of the '" << whosTurn << "' piece you would like to move (-999 to end the game): ";
    cout << choice << endl << endl;
    
    // pauses program to make it seem like AI is more human
    pauseTime();
    
    // makes the move with position passed in
    simChooseSpaceRand(possibleMovesPosition);
    
}

void Checkers::fillPossibleMoves() {
    vector<string> temp;
    if (playerOneTurn) {
        // iterates through entire board and pushes back possibleMoves whenever a piece has a possible move
        // pushed back a size two vector that has the piece and where it can move to
        for (unsigned i = 0; i <= 7; ++i) {
            for (unsigned j = 0; j <= 7; ++j) {
                
                if (isRedPiece(i,j)) {
                    
                    if (i >= 1 && j >= 1) {
                        if (isNoPiece(i-1,j-1)) {
                            temp.push_back(convertCoordinateToString(i, j));
                            temp.push_back(convertCoordinateToString(i-1,j-1));
                            possibleMoves.push_back(temp);
                            temp.clear();
                        }
                    }
                    if (i >= 1 && j <= 6) {
                        if (isNoPiece(i-1,j+1)) {
                            temp.push_back(convertCoordinateToString(i, j));
                            temp.push_back(convertCoordinateToString(i-1,j+1));
                            possibleMoves.push_back(temp);
                            temp.clear();
                        }
                    }
                }
                if (isRedKing(i, j)) {
                    if (i <= 6 && j >= 1) {
                        if (isNoPiece(i+1,j-1)) {
                            temp.push_back(convertCoordinateToString(i, j));
                            temp.push_back(convertCoordinateToString(i+1,j-1));
                            possibleMoves.push_back(temp);
                            temp.clear();
                        }
                    }
                    if (i <= 6 && j <= 6) {
                        if (isNoPiece(i+1,j+1)) {
                            temp.push_back(convertCoordinateToString(i, j));
                            temp.push_back(convertCoordinateToString(i+1,j+1));
                            possibleMoves.push_back(temp);
                            temp.clear();
                        }
                    }
                }
            }
        }
    }
    else {
        for (unsigned i = 0; i <= 7; ++i) {
            for (unsigned j = 0; j  <= 7; ++j) {
                if (isBlackPiece(i,j)) {
                    if (i <= 6 && j >= 1) {
                        if (isNoPiece(i+1,j-1)) {
                            temp.push_back(convertCoordinateToString(i, j));
                            temp.push_back(convertCoordinateToString(i+1,j-1));
                            possibleMoves.push_back(temp);
                            temp.clear();
                        }
                    }
                    if (i <= 6 && j <= 6) {
                        if (isNoPiece(i+1,j+1)) {
                            temp.push_back(convertCoordinateToString(i, j));
                            temp.push_back(convertCoordinateToString(i+1,j+1));
                            possibleMoves.push_back(temp);
                            temp.clear();
                        }
                    }
                }
                if (isBlackKing(i, j)) {
                    if (i >= 1 && j >= 1) {
                        if (isNoPiece(i-1,j-1)) {
                            temp.push_back(convertCoordinateToString(i, j));
                            temp.push_back(convertCoordinateToString(i-1,j-1));
                            possibleMoves.push_back(temp);
                            temp.clear();
                        }
                    }
                    if (i >= 1 && j <= 6) {
                        if (isNoPiece(i-1,j+1)) {
                            temp.push_back(convertCoordinateToString(i, j));
                            temp.push_back(convertCoordinateToString(i-1,j+1));
                            possibleMoves.push_back(temp);
                            temp.clear();
                        }
                    }
                }
            }
        }
    }
    
}

// stops the simulation for a certain amount of time, as simulation goes on pause time gets shorter
void Checkers::pauseTime() {

    if (isSinglePlayer) {
        sleep_for(milliseconds(1000));
        return;
    }
    
    if (sleepTime - 20 < 150) {
        sleep_for(milliseconds(150));
        return;    
    }
    
    sleep_for(milliseconds(sleepTime));

    ++moveTime;
    if (moveTime % 20 == 0) {
        sleepTime = sleepTime - 20;
    }
    
}



