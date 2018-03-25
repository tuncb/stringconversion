#pragma once
#include <string>
#include <boost\lexical_cast.hpp>

namespace stringconversion {
  template <typename T> inline std::string to_string(T t)
  {
    return boost::lexical_cast<std::string>(t);
  }

  template <typename T> inline T from_string(const std::string& str)
  {
    return boost::lexical_cast<T>(str);
  }
  template <typename T, typename IteratorType> inline T from_string(IteratorType b, size_t n)
  {
    return boost::lexical_cast<T>(b, n);
  }
}