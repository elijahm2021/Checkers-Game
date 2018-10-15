#include "Checkers.h"


void Checkers::singlePlayer() {
    // prompts user until valid input
    do {
        cout << endl << "Enter the difficulty you would like to play on." << endl << endl;
        cout << "'1' for easy, '2' for medium, '3' for hard: ";
        cin >> userInput;
        if (userInput == "1") {
            easyMode();
            break;
        }
        else if (userInput == "2") {
            // break;
        }
        else if (userInput == "3") {
            hardMode();
        }
        cout << "Please enter one of the three options ('1', '2', or '3') to play the game: ";
    } while(true); 
}

// random moves by AI
void Checkers::easyMode() {
    system("clear");
    
    // loop that discontinues when a player has won
    while (true) {
        drawBoard();
        if (playerOneTurn) {
            
            if (noMove()) {
                cout << "All of player one's pieces are blocked." << endl << endl;
                cout << "Player two wins!" << endl << endl;
                cout << "Thanks for playing!" << endl << endl << endl;
                return;
            }
            if (get<0>(prevMove) != "") {
                cout << "Player two moved from " << get<0>(prevMove) << " to " << get<1>(prevMove) << endl << endl;
            }
            cout << "Player one's turn" << endl << endl;
            choosePiece();
            chooseSpace();
            
            if (endGame()) {
                drawBoard();
                cout << "Player one wins!" << endl << endl;
                cout << "Thanks for playing!" << endl << endl;
                return;
            }
            playerOneTurn = false;
        }
        else {
            if (noMove()) {
                cout << "All of player two's pieces are blocked." << endl << endl;
                cout << "Player one wins!" << endl << endl;
                cout << "Thanks for playing!" << endl << endl;
                return;
            }
            if (get<0>(prevMove) != "") {
                cout << "Player one moved from " << get<0>(prevMove) << " to " << get<1>(prevMove) << endl << endl;
            }
            cout << "Player two's turn" << endl << endl;
            
            // AI chooses random move
            simChoosePieceRand();
            
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

void Checkers::hardMode() {
    system("clear");
    // loop that discontinues when a player has won
    while (true) {
        drawBoard();
        if (playerOneTurn) {
            
            if (noMove()) {
                cout << "All of player one's pieces are blocked." << endl << endl;
                cout << "Player two wins!" << endl << endl;
                cout << "Thanks for playing!" << endl << endl << endl;
                return;
            }
            if (get<0>(prevMove) != "") {
                cout << "Player two moved from " << get<0>(prevMove) << " to " << get<1>(prevMove) << endl << endl;
            }
            cout << "Player one's turn" << endl << endl;
            choosePiece();
            chooseSpace();
            
            if (endGame()) {
                drawBoard();
                cout << "Player one wins!" << endl << endl;
                cout << "Thanks for playing!" << endl << endl;
                return;
            }
            playerOneTurn = false;
        }
        else {
            if (noMove()) {
                cout << "All of player two's pieces are blocked." << endl << endl;
                cout << "Player one wins!" << endl << endl;
                cout << "Thanks for playing!" << endl << endl;
                return;
            }
            if (get<0>(prevMove) != "") {
                cout << "Player one moved from " << get<0>(prevMove) << " to " << get<1>(prevMove) << endl << endl;
            }
            cout << "Player two's turn" << endl << endl;
            // simChoosePieceHard();
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

/*
// int Checkers::miniMax(Piece boardRec[8][8], int depth, bool isMax) {
//     return 0;
// }
// int Checkers::min(int numOne, int numTwo) {
//     return 0;
// }
// int Checkers::max(int numOne, int numTwo) {
//     return 0;
// }
void Checkers::findBestMove(Piece boardRec[8][8], Piece& bestPiece, Piece& bestSpot) {
    
}
// int Checkers::evaluate(Piece boardRec[8][8]){
//     return 0;
// }

void Checkers::simChoosePieceHard() {
    Piece bestPiece;
    Piece bestSpot;
    
    findBestMove(board, bestPiece, bestSpot);
    
    // convertIntToCoordinate(tempPiece.getPosition());
    
    // cout << "Please enter a number to place your ";
    // if (playerOneTurn) {
    //     cout << "X (-999 to quit): ";
    // }
    // else {
    //     cout << "O (-999 to quit): ";
    // }
    // sleep_for(milliseconds(400));


    
    // placePiece();
    
    // possibleMoves.clear();
    // possibleMovePoints.clear();
}

*/