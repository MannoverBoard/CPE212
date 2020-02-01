#ifndef UTILITIES_H
#define UTILITIES_H

template<typename T,size_t N>
constexpr size_t arrayLen(const T (&arr)[N]) { return N; }

#endif
