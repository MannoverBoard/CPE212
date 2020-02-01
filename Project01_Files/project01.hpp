#ifndef PROJECT01_HPP
#define PROJECT01_HPP


#include <string>
#include <iostream>
#include <fstream>
#include "macros.h"
#include "utilities.h"


#define MACRO_Direction_attributes(callback,...) \
  EVAL(callback(Direction, , 1, __VA_ARGS__))
#define MACRO_Direction_members(callback,...) \
  EVAL(callback(Direction,Horizontal,-1, __VA_ARGS__)) \
  EVAL(callback(Direction,Vertical  ,+1, __VA_ARGS__))


#define MACRO_Rotation_attributes(callback,...) \
  EVAL(callback(Rotation, , 1, __VA_ARGS__))
#define MACRO_Rotation_members(callback,...) \
    EVAL(callback(Rotation,Clockwise       ,-1, __VA_ARGS__)) \
    EVAL(callback(Rotation,CounterClockwise,+1, __VA_ARGS__))

#define PROJECT_01_ENUM_MACROS(callback,...) \
  EVAL(callback(Direction,__VA_ARGS__)) \
  EVAL(callback(Rotation,__VA_ARGS__))
PROJECT_01_ENUM_MACROS(ENUM_MACRO_DECLARATIONS)

struct Image {
  int data[15][15];
};
//typedef int Image[MAX_ROWS][MAX_COLS];


// load the image matrix from the file described.
// if an error is ever encountered, this should return false
// if the image is successfully loaded with 0 errors, this
// should return true.
//
// This probably should be the first function you work on.
// if this function doesn't function correctly then your
// project is dead in the water.
bool LoadImage(const std::string & imageFile, Image& image);

// This will flip the matrix according to the direction provided.
// a value of false is returned when an unknown Flip value is given
// otherwise a value of true is returned.
bool Flip(struct Image& image, const Direction d);

// this will rotate the matrix according to the direction provided.
// a value of false is returned when an unknown Rotation value is given
// otherwise a value of true is returned.
bool Rotate(struct Image& image, const Rotation r);

// this will transpose the image, which flips it across the diagonal.
// this diagonal goes from the top left to the bottom right.
void Transpose(struct Image& image);


#endif // end define PROJECT01_HPP
