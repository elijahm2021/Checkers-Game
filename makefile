#Playlist makefile

#Variables
COMPILE = g++
FLAGS = -W -Wall -Werror -std=c++11
OBJS = Checkers.o Piece.o Simulate.o SinglePlayer.o

#Targets

all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o play main.cpp $(OBJS) 
	
Checkers.o: Checkers.cpp Checkers.h Piece.h 
	$(COMPILE) $(FLAGS) -c Checkers.cpp
	
Piece.o: Piece.cpp Piece.h 
	$(COMPILE) $(FLAGS) -c Piece.cpp
	
Simulate.o: Simulate.cpp Checkers.h  
	$(COMPILE) $(FLAGS) -c Simulate.cpp
	
SinglePlayer.o: SinglePlayer.cpp Checkers.h  
	$(COMPILE) $(FLAGS) -c SinglePlayer.cpp
	



clean:
	rm -rf *~ *.o play
