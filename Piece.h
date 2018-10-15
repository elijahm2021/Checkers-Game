#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <ctype.h>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <utility>
#include <stdio.h>
#include <string.h>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

// NONE means there is no piece at that coordinate
enum Type {REDNORMAL, REDKING, BLACKNORMAL, BLACKKING, NONE};

class Piece {

  protected:
    // coordinates of checker piece (row goes from 0-7 left to right)
    //                              (column goes from 0-7 up to down)
    int row;
    int column;
    
    // represents the type of checker piece it is
    Type checkerType;
    
    // jumps is a vector of strings of possible jumps that the Piece object can make
    vector<string> jumps;
    
  public:
    
    
    Piece();
    Piece(Type checkerType, int row, int column);
    
    // returns type of checker piece
    Type getType() const;
    
    // returns position of checker piece
    string getPosition() const;
    
    // returns an 'o' if a black piece or an 'x' if red piece
    char pieceCharacter() const;
    
    // returns the possible jumps this piece can make
    vector<string> getJumps() const;
    
    // adds on to the jumps vector with a passed in coordinate
    void pushJump(int row, int column);
    
    // gives a new type to current passed in checker piece
    void newType(Type checkerType);
    
    // clears the jumps vector of piece
    void clearJumps();
    
  private:
    
    
    string convertCoordinateToString(int row, int column) const;
    
};

#endif 

