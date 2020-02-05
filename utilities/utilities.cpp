#include <regex>
#include <iterator>
#include "utilities.h"

std::string quoted11(const std::string& s, const char delim, const char escape) {
  const std::regex pattern(std::string("[") + delim + std::string("]"));
  const std::string escape_str(1,escape);
  std::string result;
  std::regex_replace(std::back_inserter(result),s.begin(),s.end(),pattern,escape_str);
  return result;
}
