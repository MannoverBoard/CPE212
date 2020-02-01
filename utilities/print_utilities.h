#ifndef PRINT_UTILITIES
#define PRINT_UTILITIES

#include <ostream>
#include <sstream>

template<typename T,size_t R,size_t C>
std::string toString(const T(&a)[R][C]) {
  std::ostringstream os;
  os << '[';
  for(size_t r;r<R;++r) {
    os << '[';
    for(size_t c;c<(C-1);++c) {
      os << a[r][c] << ',';
    }
    os << a[r][C-1] << ']'
    #ifdef PRINT_ARRAYS_WITH_NEWLINES
      << '\n'
    #endif
    ;
  }
  os << ']';
  return os.str();
}

template<typename T,size_t R,size_t C>
std::ostream& operator<<(std::ostream& os, const T(&a)[R][C]) {
  os << toString(a);
  return os;
}

#endif
