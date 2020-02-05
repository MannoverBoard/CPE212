#!/bin/bash

g++ -std=c++11 -c ../utilities -I ../utilities
g++ -std=c++11 -c *.cpp -I ../utilities
g++ -std=c++11 ../utilities/*.o *.o -o a.out
