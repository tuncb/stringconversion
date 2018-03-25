#include <boost/test/unit_test.hpp>
#include <stringconversion/Containers.h>

BOOST_AUTO_TEST_SUITE(containers)

BOOST_AUTO_TEST_CASE(int_delimeters_vector)
{
  std::vector<int> numbers;
  std::string str = "53,45,67,89;45;89;1002";

  stringconversion::generate_from_delimeted<int>(str.begin(), str.end(), ",;", std::back_inserter(numbers));
  auto answers = { 53, 45, 67, 89, 45, 89, 1002 };
  BOOST_CHECK_EQUAL_COLLECTIONS(numbers.begin(), numbers.end(), answers.begin(), answers.end());
}

BOOST_AUTO_TEST_CASE(double_delimeters_array)
{
  std::array<double, 7> numbers;
  std::string str = "53.5,45.5,67.5,89.5;45.5;89.5;1002.5";

  stringconversion::generate_from_delimeted<double>(str.begin(), str.end(), ",;", numbers.begin());
  auto answers = { 53.5, 45.5, 67.5, 89.5, 45.5, 89.5, 1002.5 };
  BOOST_CHECK_EQUAL_COLLECTIONS(numbers.begin(), numbers.end(), answers.begin(), answers.end());
}

BOOST_AUTO_TEST_SUITE_END()