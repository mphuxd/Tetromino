#
#Matthew Pham
#998804208

all: tetris

tetris: Tetromino.o Board.o
	g++ -o tetris tetris.cpp Tetromino.o Board.o -Wall 
tetris.o: Tetromino.cpp Board.cpp
	g++ -c Tetromino.cpp Board.cpp -Wall
Tetromino.o: Tetromino.cpp Tetromino.h
	g++ -c Tetromino.cpp -Wall 

Board.o: Tetromino.cpp Board.h
	g++ -c Board.cpp Tetromino.cpp -Wall
clean:
	rm tetris Tetromino.o Board.o




