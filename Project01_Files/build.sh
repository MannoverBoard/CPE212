#!/bin/bash

clear;rm *.out;rm *.o;g++ *.cpp -c -I ../utilities -std=c++11 ; g++ *.o;./a.out p01input5.txt

