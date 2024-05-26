#!/bin/bash

mkdir lib
cd lib
git clone git@github.com:google/googletest.git

cd ..
mkdir build
cd build
cmake ..
make