@echo off

conan export-pkg . stringconversion/0.2.0@tuncb/pangea -s os=Windows -s compiler="Visual Studio" -s arch="x86_64" -s compiler.toolset=v141 --force || goto :error
conan test ./test_package stringconversion/0.2.0@tuncb/pangea -s build_type=Debug -s os=Windows -s compiler="Visual Studio" -s arch="x86_64" -s compiler.toolset=v141 || goto :error
conan test ./test_package stringconversion/0.2.0@tuncb/pangea -s build_type=Release -s os=Windows -s compiler="Visual Studio" -s arch="x86_64" -s compiler.toolset=v141 || goto :error

goto :success

:error
echo Failed with error #%errorlevel%.
exit /b %errorlevel%

:success
echo Success!
