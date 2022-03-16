#!/bin/bash

flex -V
bison -V
gcc -v

echo "=================================\n"

flex -o flex.yy.c flex.l
gcc -o test flex.yy.c
./test input.txt