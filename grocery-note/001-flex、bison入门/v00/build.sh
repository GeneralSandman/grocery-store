#!/bin/bash

flex -V
bison -V
gcc -v

echo "=================================\n"

flex -o flex.yy.c flex.l
bison --yacc -dv -o bison.y