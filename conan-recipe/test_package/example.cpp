#include <stringconversion/Fundamentals.h>
#include <string>
#include <iostream>

int main()
{
  std::string str = "-52750";
  int i = stringconversion::from_string<int>(str);
  std::cout << "The number should be -52750 => " << i << "\n"; 
}