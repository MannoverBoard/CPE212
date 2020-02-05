#!/bin/bash

./build.sh;
find . -type f -name 'test_*' | xargs -I {} ./a.out {}
