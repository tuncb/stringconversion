#pragma once
#include <bitset>
#include <stringconversion/Fundamentals.h>

namespace stringconversion {

  template <typename T, class InputIterator, class BackInserterIterator> 
  void generate_from_delimeted(InputIterator b, InputIterator e, const char* d,  BackInserterIterator iter)
  {
    // http://stackoverflow.com/questions/5505965/fast-string-splitting-with-multiple-delimiters
   
    // create a bitset operator for comparison
    std::bitset<255> delims;
    while (*d) {
      unsigned char code = *d++;
      delims[code] = true;
    }

    // 
    bool in_token = false;
    auto beg = b;
    for (auto it = b; it != e; ++it) {
      if (delims[*it]) {
        if (in_token) {
          // I used (it - beg) instead of std::distance, just to make sure iterators are random access
          *iter++ = stringconversion::from_string<T>(&(*beg), std::distance(beg,it));
          in_token = false;
        }
      }
      else if (!in_token) {
        beg = it;
        in_token = true;
      }
    }
    if (in_token) {
      *iter++ = stringconversion::from_string<T>(&(*beg), e - beg);
    }
  }







}