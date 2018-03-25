PROJECT(stringconversion_tester)
cmake_minimum_required(VERSION 2.8.12)

include(../../conan.cmake)
conan_cmake_run(BASIC_SETUP CMAKE_TARGETS CONAN_CMAKE_MULTI
  REQUIRES "boost/1.66.0@conan/stable"
)

set(SOURCES 
  "./source/main.cpp"
  "./source/containers.cpp"
  "./source/fundementals.cpp"
  "./source/stringmap.cpp"
)

set(STRINGCONVERSION_LIB 
  "../stringconversion/include/stringconversion/containers.h"
  "../stringconversion/include/stringconversion/definitions.h"
  "../stringconversion/include/stringconversion/fundamentals.h"
  "../stringconversion/include/stringconversion/stringmap.h"
  )

add_executable(stringconversion_tester ${SOURCES} ${STRINGCONVERSION_LIB})
target_include_directories(stringconversion_tester PRIVATE "../stringconversion/include/")
target_link_libraries(stringconversion_tester CONAN_PKG::boost)  

source_group("stringconversion_library" FILES ${STRINGCONVERSION_LIB})

