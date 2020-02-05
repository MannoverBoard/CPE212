#include <regex>
#include <string>
#include <iterator>
#include "utilities.h"

using namespace std::string_literals;

std::string quoted11(const std::string& s, const char delim, const char escape) {
  const std::regex pattern( "["s + delim + "]"s );
  const std::string escape_str(1,escape);
  std::string result;
  std::regex_replace(std::back_inserter(result),s.begin(),s.end(),pattern,escape_str);
  return ( '"' + result + '"' );
}
