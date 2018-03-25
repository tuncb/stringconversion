from conans import ConanFile

class StringConversionConan(ConanFile):
    name = "stringconversion"
    version = "0.2.0"
    license = "https://www.apache.org/licenses/LICENSE-2.0"
    url = "https://github.com/tuncb/stringconversion"
    description = ("A library for string conversion")
    requires = "boost/1.66.0@conan/stable"

    def package(self):
        self.copy("*", dst="stringconversion", src="../projects/stringconversion/include/stringconversion")
    def package_info(self):
        self.cpp_info.includedirs = ['.']
