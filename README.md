# Spike-Simulator
Spike Simulator is a cross platform application for simulating different spike robotics applications.

## Building & Platforms
Spike Simulator is meant to run cross platform so its build system is setup to compile for different platforms.
MSVC is the target for windows compilation, and Clang for everything else.

### Windows
To build on windows simply open cmd to the project folder and run
```
build_windows.bat
```
Or just run the bat file directly. This will generate a visual studio solution in the build folder,
which can further be used for compiling etc.
### Linux
To build on linux, open a terminal to the project folder and run
```
./build_linux.sh
```
Or just run the shell script directly. Note the file may require `chmod +x build_linux.sh` to run.


## Notes
