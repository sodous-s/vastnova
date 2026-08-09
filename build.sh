#!/bin/bash
# Build script for VastNova compiler

echo "Building VastNova..."

g++ -std=c++17 src/main.cpp src/CodeGen.cpp -I include $(llvm-config --cxxflags --ldflags --libs core) -fexceptions -o vastnova

echo "Build successful! Run ./vastnova --help for usage."
