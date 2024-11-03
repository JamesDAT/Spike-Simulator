#!/bin/bash

echo "Building project for Linux (Clang)..."

# Create the build directory for Linux
mkdir -p build/linux

# Navigate to the build directory
cd build/linux

# Run CMake with Make as the generator
cmake -G "Unix Makefiles" -DCMAKE_CXX_COMPILER=clang++ ../..
if [ $? -ne 0 ]; then
    echo "CMake configuration failed!"
    exit 1
fi

cmake --build .
if [ $? -ne 0 ]; then
    echo "Build failed!"
    exit 1
fi

echo "Build completed successfully!"
