#!/bin/bash

rm -f -- *.o 
rm -f -- *.exe 
rm -f -- *.out
here="${PWD}";
cd ../utilities
g++ -std=c++14 -c *.cpp 
cd "$here"
g++ -std=c++14 -c -I../utilities  *.cpp
g++ -std=c++14    -I../utilities  ../utilities/*.o ./*.o -o a.out 
