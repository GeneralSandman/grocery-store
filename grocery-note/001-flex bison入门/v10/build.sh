#!/bin/bash

flex -V
bison -V
gcc -v

echo "=================================\n"

bison --yacc -dv -o bison.c bison.y # bison.c bison.h bison.output
flex -o flex.yy.c flex.l
gcc -o test flex.yy.c bison.c
./test