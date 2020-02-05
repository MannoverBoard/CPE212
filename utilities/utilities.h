#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

template<typename T,size_t N>
constexpr size_t arrayLen(const T (&arr)[N]) { return N; }

std::string quoted11(const std::string& s, const char delim='"', const char escape = '\\');

#endif
