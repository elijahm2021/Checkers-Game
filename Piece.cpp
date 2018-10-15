#include "Piece.h"
Piece::Piece(){}

//piece constructor 
Piece::Piece(Type checkerType, int row, int column) {
    this->checkerType = checkerType;
    this->row = row;
    this->column = column;

}

//returns the type of the piece
Type Piece::getType() const {
    return checkerType;
}

//returns corresponding character to type of piece
char Piece::pieceCharacter() const{
    switch (checkerType) {
        case REDNORMAL: return 'x';
        case BLACKNORMAL: return 'o';
        case REDKING: return 'X';
        case BLACKKING: return 'O';
        case NONE: return ' ';
    }
    return ' ';
}

//fills the vector jumps within piece
void Piece::pushJump(int row, int column) {
    jumps.push_back(convertCoordinateToString(row, column));
}


string Piece::convertCoordinateToString(int row, int column) const{
    row = abs(row - 8);
    char columnChar = 'A' + column; 
    string returnString;
    returnString = to_string(row) + columnChar;
    return returnString;
}

//returns the position on the board when called
string Piece::getPosition() const{
    return convertCoordinateToString(row, column);
}

//returns the vector jumps within piece
vector<string> Piece::getJumps() const{
    return jumps;
}

//empties the vector jumps
void Piece::clearJumps() {
    jumps.clear();
}

//changes a piece's type 
void Piece::newType(Type checkerType) {
    this->checkerType = checkerType;
}