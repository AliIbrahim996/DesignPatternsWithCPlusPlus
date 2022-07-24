setlocal

REM install tools
conan install . --profile=win_vc15_x64  --build missing || exit /b 2

REM install workspace
conan workspace install . %* || exit /b 3

call activate.bat
@echo on

REM create solution
cmake  -DCMAKE_GENERATOR_TOOLSET=v141 -DCONAN_CMAKE_SILENT_OUTPUT=ON -Wno-dev . || exit /b %ERRORLEVEL%