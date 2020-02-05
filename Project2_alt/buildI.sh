#!/bin/bash

g++ -std=c++11 -dD -E -c ../utilities -I ../utilities
g++ -std=c++11 -dD -E -c *.cpp -I ../utilities
g++ -std=c++11 -dD -E ../utilities/*.o *.o -o a.out
