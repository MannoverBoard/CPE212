#include "project01.hpp"
#include <fstream>
#include <regex>

PROJECT_01_ENUM_MACROS(ENUM_MACRO_DEFINITIONS)

using namespace std;
const regex comment_line(R"(^\s*#)");
const regex blank_line(R"(^\s*$)");
const regex number(R"((\d+))");
smatch m;

bool LoadImage(const std::string & imageFile, Image& image)
{
  std::string line;
  auto fin = ifstream(imageFile);
  if(!fin.is_open()) { return false; }
  size_t row = 0;
  while(1) {
    getline(fin,line);
    if(regex_match(line,blank_line) || regex_match(line,comment_line)) {
      continue;
    }
    if(!regex_search(line,m,number)) { continue; }
    size_t col = 0;
    for(auto num_str:m) {
        image.data[row][col]=stoi(num_str);
        col++;
        if(col>=arrayLen(image.data[0])) { break; }
    }
    row++;
    if(row>=arrayLen(image.data)) { break; }
  }
  return true;
}

bool Flip(Image& image, const Direction d)
{
    // Implement this function
    return true;
}

bool Rotate(Image& image, const Rotation r)
{
    // Implement this function
    return true;
}

void Transpose(Image& image)
{
    // Implement this function
}
