# OpenGL sample project #

## Clone ##

<!--
git submodule add https://github.com/glfw/glfw src/external/glfw
git submodule add https://github.com/rikusalminen/glxw src/external/glxw
-->

To checkout the code, clone the repo recursively to get all the submodules:
```
git clone --recursive repo-url
```

Or do it manually:
```
git submodule update --init --recursive
```

## Build ##

For Windows under the visual studio command prompt:
```
cd build
..\src\cnmake.bat ..\src
nmake
```

Or:
```
cd build
cmake ..\src
cmake --build . --config Release
```
