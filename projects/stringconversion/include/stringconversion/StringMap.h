#pragma once
#include <stringconversion/Fundamentals.h>

namespace stringconversion {

  template <typename T, typename MapType> T get_property(const MapType& map, const std::string& name, T default_value)
  {
    auto iter = map.find(name);
    if (iter != map.end())
    {
      return stringconversion::from_string<T>(iter->second);
    }
    else return default_value;
  }
}