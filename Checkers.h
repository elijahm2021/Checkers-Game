#ifndef CHECKERS_H
#define CHECKERS_H

#include "Piece.h"

class Checkers {
    
  private:
    
    // curRow and curColumn are coordinates of the checker piece the user wants to move
    int curRow;
    int curColumn;
    
    // newRow and newColumn are coordinates where the user wants to move the selected checker piece
    int newRow;
    int newColumn;
    
    // sleepTime and moveTime are used in the pauseTime function in the Simulate.h file for speeding up purposes in the simulation mode
    int sleepTime;
    int moveTime;
    
    // playerOneTurn keeps track of who's turn it is throughout the program
    bool playerOneTurn;
    
    // isConsecutiveHop is used in the chooseSpace function only after the program has come from the 
    //     movePiece function when there is a possible consecutive hop.
    //     Gives different message to user when true.
    bool isConsecutiveHop;
    
    // made true after single player mode is selected
    bool isSinglePlayer;
    
    // 2D vector of Piece objects
    Piece board [8][8];
    
    // used many times throughout program so I made it into a private member variable
    string userInput;
    
    // the first string is the checker piece was initially at and the second position is the where the c
    pair <string, string> prevMove;
    
    // holds strings of coordinates of pieces that have possible jumps
    // doesn't store where it can jump because each object Piece already has a private member vector "jumps" that store where it can jump to
    vector <Piece> redJumps;
    vector <Piece> blackJumps;
    
    // used in the simulation mode 
    // the first string in the inside vectors is the piece that has possible move(s)
    // the following string(s) in the inside vectors are of coordinates of where it can move
    vector <vector<string> > possibleMoves;
    
  public:
    
    // sets board up with where the pieces are being set in 2D array
    Checkers();
    Checkers(int t);
    
    
    void drawBoard() const;
    void twoPlayer();
    
    // random moves between two computer players
    void simulate();
    
    // singlePlayer gets input from user and calls a difficulty mode function
    void singlePlayer();
    
    // easyMode is against a random move generated AI
    void easyMode();
    
    // hardMode is against miniMax algorithm
    void hardMode();

  private:
    // takes user input and checks if it is valid
    void choosePiece();
    void chooseSpace();
    
    // actually moving the pieces around and changing the inital piece's coordinate to Piece type NONE
    // and changing hopped Pieces to Piece type NONE
    void movePiece();
    
    // AI chooses random piece from possible moves available to it
    void simChoosePieceRand();
    
    // AI chooses random space to move selected checker piece
    // possibleMovePosition is the position in the vector of possible moves that the AI will use
    void simChooseSpaceRand(int possibleMovesPosition);
    
    // if the AI decides to make a consecutive jump
    void simChooseAnotherSpaceRand();
    
    // This calls Minimax algorithm
    void simChoosePieceHard();
    
    // different from movePiece because of the chance factor of consecutively jumping over another piece
    // moves the piece from old spot to new spot and clearing the piece that it may have hopped over
    void simMovePiece();
    
    // the time calculated in between turns to make AI seem like its taking time thinking before moving its piece
    // also easier to see where AI moves
    void pauseTime();
    
    // gets all possible moves that the current player can move to and fills possibleMoves vector
    void fillPossibleMoves();
    
    // gets all possible jumps and fills each Piece's "jumps" vector of where teh coordinates of where the piece can jump to
    // also fills redJumps and blackJumps of the  coordinates of the pieces that have possible jumps
    void fillJumps();
    
    // clears each Piece object's "jumps" vector
    void emptyJumps();
    
    // clears redJumps and black Jumps
    void emptyPieces();
    
    // Checks if the moved checker piece made it to the end of the checker board
    //     If it did, then the piece will be made a king if it wasn't already
    void makeKing();
    
    // MiniMax functions
    // int miniMax(Piece boardRec[3][3], int depth, bool isMax);
    // int min(int numOne, int numTwo);
    // int max(int numOne, int numTwo);
    // void findBestMove(Piece boardRec[8][8], Piece& bestPiece, Piece& bestSpot);
    // int evaluate(Piece boardRec[8][8]);
    
    // returns whether or not there is anotherJump available after making one
    // also fills redJumps and blackJumps 
    bool anotherJump(int row, int column);
    
    // checks user input to make sure that the
    bool isValidInput() const;
    
    // checks to see the space is a part of the 
    bool isInvalidSpace(int row, int column) const;
    
    // checking to see if the chosen checker space is filled
    bool isSpaceFilled() const;
    
    // checking to see if the chosen checker piece made a valid move without jumping
    bool isValidMove() const;
    
    // iterates thorugh board and checks if a player had lost all of their pieces 
    bool endGame() const;
    
    // checks board to see if given coordinate's piece can move or not
    bool canNotMove(int row, int column) const;
    
    // iterates through the board and calls canNotMove nad returns whether or not a player has an available move to them
    bool noMove(); 
    
    // checks given coordinates to see if they are the piece the function is looking for
    bool isRedPiece(int row, int column) const;
    bool isBlackPiece(int row, int column) const;
    bool isBlackKing(int row, int column) const; 
    bool isKing(int row, int column) const;
    bool isRedKing(int row, int column) const;
    bool isRedNormal(int row, int column) const;
    bool isBlackNormal(int row, int column) const;
    bool isNormal(int row, int column) const;
    bool isNoPiece(int row, int column) const;
    
    // converts the passed in coordinates and returns a string in the format of a number and a letter Ex. 4C
    string convertCoordinateToString(int row, int column);
    
    // converts the userInput private member string into the passed in integer coordinates 
    void convertStringToCoordinate(int &row, int &column);
    
};

#endif