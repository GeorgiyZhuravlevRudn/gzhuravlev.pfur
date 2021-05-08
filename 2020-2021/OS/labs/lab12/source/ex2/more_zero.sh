#!/bin/bash

g++ more_zero.cpp -o more_zero

./more_zero

case $? in
    
     0) echo "number is > 0";;
     1) echo "number is = 0";;
     2) echo "number is < 0";;
     
esac
