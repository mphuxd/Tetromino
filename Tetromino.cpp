//
//Matthew Pham
//998804208
//Tetromino.cpp
//
#include "Tetromino.h"
#include<iostream>
#include<stdexcept>
using namespace std;

void Tetromino::print(void) const{
  cout << name() << " at";
  for ( int i = 0; i < 4; i++ )
    cout << " (" << x[i] << "," << y[i] << ")";
  cout << endl; 
}

bool Tetromino::overlap(const Tetromino &t) const{
  for ( int i = 0; i < 4; i++ ){
    for ( int j = 0; j < 4; j++ ){
      if ( x[i] == t.x[j] && y[i] == t.y[j] )
        return true;
    }
  }
  return false;
}

void Tetromino::rotate(int nrot){
  for ( int irot = 0; irot < nrot; irot++ )
    for ( int i = 1; i < 4; i++ ){
      const int dx = x[i] - x[0];
      const int dy = y[i] - y[0];
      x[i] = x[0] - dy;
      y[i] = y[0] + dx;
    }
}
I::I(int posx, int posy, int orientation){
  x[0] = posx + 0; y[0] = posy + 0;
  x[1] = posx + 0; y[1] = posy + 1;
  x[2] = posx + 0; y[2] = posy + 2;
  x[3] = posx + 0; y[3] = posy + 3;
  rotate(orientation);
}

O::O(int posx, int posy, int orientation){
  x[0] = posx + 0; y[0] = posy + 0;
  x[1] = posx + 1; y[1] = posy + 0;
  x[2] = posx + 0; y[2] = posy + 1;
  x[3] = posx + 1; y[3] = posy + 1;
  rotate(orientation);
}

T::T(int posx, int posy, int orientation)
{
  x[0] = posx + 0; y[0] = posy + 0;
  x[1] = posx - 1; y[1] = posy + 1;
  x[2] = posx + 0; y[2] = posy + 1;
  x[3] = posx + 1; y[3] = posy + 1;
  rotate(orientation);
}

J::J(int posx, int posy, int orientation){
  x[0] = posx + 0; y[0] = posy + 0;
  x[1] = posx + 1; y[1] = posy + 0;
  x[2] = posx + 1; y[2] = posy + 1;
  x[3] = posx + 1; y[3] = posy + 2;
  rotate(orientation);
}

L::L(int posx, int posy, int orientation){
  x[0] = posx + 0; y[0] = posy + 0;
  x[1] = posx + 1; y[1] = posy + 0;
  x[2] = posx + 0; y[2] = posy + 1;
  x[3] = posx + 0; y[3] = posy + 2;
  rotate(orientation);
}

S::S(int posx, int posy, int orientation){
  x[0] = posx + 0; y[0] = posy + 0;
  x[1] = posx + 1; y[1] = posy + 0;
  x[2] = posx + 1; y[2] = posy + 1;
  x[3] = posx + 2; y[3] = posy + 1;
  rotate(orientation);
}

Z::Z(int posx, int posy, int orientation){
  x[0] = posx + 0; y[0] = posy + 0;
  x[1] = posx + 1; y[1] = posy + 0;
  x[2] = posx - 1; y[2] = posy + 1;
  x[3] = posx + 0; y[3] = posy + 1;
  rotate(orientation);
}

char I::name(void) const { return 'I'; }
const char* I::color(void) const {return "cyan";}

char O::name(void) const { return 'O'; }
const char* O::color(void) const {return "yellow";}

char T::name(void) const { return 'T'; }
const char* T::color(void) const {return "purple";}

char J::name(void) const { return 'J'; }
const char* J::color(void) const {return "blue";}

char L::name(void) const { return 'L'; }
const char* L::color(void) const {return "orange";}

char S::name(void) const { return 'S'; }
const char* S::color(void) const {return "lime";}

char Z::name(void) const { return 'Z'; }
const char* Z::color(void) const {return "red";}


Tetromino *Tetromino::makeTetromino(char type, int posx, int posy,
 int orientation){
  if ( orientation < 0 || orientation > 3 )
    throw invalid_argument("invalid orientation");

  if ( type == 'I' )
    return new I(posx,posy,orientation);
  else if ( type == 'O' )
    return new O(posx,posy,orientation);
  else if ( type == 'T' )
    return new T(posx,posy,orientation);
  else if ( type == 'J' )
    return new J(posx,posy,orientation);
  else if ( type == 'L' )
    return new L(posx,posy,orientation);
  else if ( type == 'S' )
    return new S(posx,posy,orientation);
  else if ( type == 'Z' )
    return new Z(posx,posy,orientation);
  else
    throw invalid_argument("invalid type");

  return 0;
}

int Tetromino::getX(int i) const {
    return x[i];
}

int Tetromino::getY(int i) const {
    return y[i];
}

void Tetromino::draw(void) const {
    int i;
    for (i=0; i < 4; i++){
    cout << "<rect fill=\"" << color() << "\" stroke=\"black\" " << "x=\""<< getX(i) * 50 << "\" y=\"" << getY(i) * 50<< "\" width=\"50\" height=\"50\"/>" << endl;
    }
}






