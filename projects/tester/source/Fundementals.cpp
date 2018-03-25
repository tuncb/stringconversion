#include <boost/test/unit_test.hpp>
#include <stringconversion/Fundamentals.h>

BOOST_AUTO_TEST_SUITE(fundementals)

BOOST_AUTO_TEST_CASE(str_to_int)
{
  std::string str = "-52750";
  int i = stringconversion::from_string<int>(str);
  BOOST_CHECK_EQUAL(i, -52750);
}

BOOST_AUTO_TEST_CASE(int_to_str)
{
  int i = -52750;
  std::string str = stringconversion::to_string(i);
  BOOST_CHECK_EQUAL(str, "-52750");
}

BOOST_AUTO_TEST_SUITE_END()