#!/bin/bash

mkdir -p build

cd build

# Run cmake to generate Makefile
cmake ..
# cmake -DCMAKE_BUILD_TYPE=Debug ..
# cmake -DCMAKE_BUILD_TYPE=Release ..

# Run make to build the project
make

