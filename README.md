# Parallel White Noise via Fragment Shader #

This is a GLSL + GLFW (re)implementation of the earlier [Cg version](https://github.com/1iyiwei/noise/tree/master/WhiteNoise/) of [parallel white noise generation on a GPU via cryptographic hash](https://dl.acm.org/citation.cfm?id=1342263).

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
cmake ..\src
cmake --build . --config Release
```

## Run ##

```
cd build
./bin/Release/White.exe [width (int) height (int) animate (0 or 1)]
```
Press escape key to quit, any other key to change the noise key per frame.
