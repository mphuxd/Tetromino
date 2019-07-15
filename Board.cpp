//
//Matthew Pham
//998804208
//
#include "Board.h"
#include "Tetromino.h"
#include <iostream>
#include <vector>
using namespace std;

bool Board::fits_on_board(const Tetromino &t) const {
    int i;
    for (i = 0; i < 3; i++){
        if ((t.getX(i) < 0) || (t.getY(i) < 0)) return true;
        if ((t.getX(i) > size_x) || (t.getY(i) > size_y)) return true;
    }
return false;
}

void Board::addTetromino(char type, int x, int y, int orientation){
    Tetromino *t1;
    unsigned int i;
    t1 = Tetromino::makeTetromino(type, x, y, orientation);
    if (fits_on_board(*t1)) throw invalid_argument("does not fit on the board");
    for (i = 0; i < tList.size(); i++){
        if (t1->overlap(*tList[i])) throw invalid_argument("overlap");
    }
    tList.push_back(t1);
}

void Board::draw(void) const {
	unsigned int i;
	cout << "<?xml version=\"1.0\" encoding=\"utf-8\"  standalone=\"no\"?>" <<endl;
	cout << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" "<< endl;
	cout << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\"> "<< endl;
	cout << "<svg width=\"570\" height=\"570\" viewBox=\"0 0 550 550\" "<< endl;
	cout << "xmlns=\"http://www.w3.org/2000/svg\" " << endl;
	cout << "xmlns:xlink=\"http://www.w3.org/1999/xlink\" >"<< endl;
	cout << "<g transform=\"matrix(1,0,0,-1,50,550)\">"<< endl;

	cout << "<rect fill=\"white\" stroke=\"black\" x=\"0\" y=\"0\"  width=\""<< size_x * 50 <<"\" height=\"" << size_y * 50 <<"\"/>" << endl; 

	for (i = 0; i < tList.size(); i++){
        	Tetromino *t = tList[i];
        	t->draw();
    	}

	cout << "</g>" << endl;
	cout << "</svg>" << endl;
}


