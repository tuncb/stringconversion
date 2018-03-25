#include <boost/test/unit_test.hpp>
#include <stringconversion/StringMap.h>
#include <unordered_map>

BOOST_AUTO_TEST_SUITE(stringmap)

BOOST_AUTO_TEST_CASE(property_to_int)
{
  std::unordered_map<std::string, std::string> map;
  map["int"] = "-52750";

  int i = stringconversion::get_property(map, "int", 5);
  BOOST_CHECK_EQUAL(i, -52750);

  int i2 = stringconversion::get_property(map, "int1111", 5);
  BOOST_CHECK_EQUAL(i2, 5);
}

BOOST_AUTO_TEST_SUITE_END()