#include <fstream>
#include <regex>
#include "project01.hpp"

PROJECT_01_ENUM_MACROS(ENUM_MACRO_DEFINITIONS)

using namespace std;
const regex comment_line("^[ \\t]*#.*");
const regex blank_line("^\\s*");
const regex number_pattern("(\\d+)");

bool LoadImage(const std::string & imageFile, Image& image)
{
  std::string line;
  auto fin = ifstream(imageFile);
  if(!fin.is_open()) { return false; }
  size_t row = 0;
  smatch m;
  while(1) {
    getline(fin,line);
    if(regex_match(line,blank_line) || regex_match(line,comment_line) ) {
      continue;
    }
    if(!regex_search(line,m,number_pattern)) { continue; }
    size_t col = 0;
    auto subject{line};
    while(regex_search(subject,m,number_pattern)) {
      image[row][col]=stoi(m[0].str());
      col++;
      if(col>=arrayLen(image[0])) { break; }
      subject = m.suffix().str();
    }
    row++;
    if(row>=arrayLen(image)) { break; }
  }
  return true;
}

template<typename T,size_t R,size_t C>
void transpose(T(&data)[R][C]) {
  static_assert(R==C,"Rows must equal Columns");
  for(size_t r=0;r<R;++r) {
    for(size_t c=0;c<r;++c) {
      std::swap(data[r][c],data[c][r]);
    }
  }
}

template<typename T,size_t R,size_t C>
bool flip(T(&data)[R][C], const Direction d) {
  if(!isValid(d)) { return false; }
  switch(d) {
  case Direction::Horizontal:
    for(size_t r=0;r<R;++r) {
      for(size_t c=0;c<(C/2);++c) {
        std::swap(data[r][c],data[r][C-c-1]);
      }
    }
    break;
  case Direction::Vertical:
    for(size_t r=0;r<(R/2);++r) {
      for(size_t c=0;c<C;++c) {
        std::swap(data[r][c],data[R-r-1][c]);
      }
    }
  }
  return true;
}


bool Flip(Image& image, const Direction d) {
  return flip(image,d);
}

bool Rotate(Image& image, const Rotation r) {
    if(!isValid(r)) { return false; };
    transpose(image);
    switch(r) {
    case Rotation::       Clockwise: flip(image,Direction::Vertical  ); break;
    case Rotation::CounterClockwise: flip(image,Direction::Horizontal); break;
    }
    return true;
}

void Transpose(Image& image) {
  transpose(image);
}
