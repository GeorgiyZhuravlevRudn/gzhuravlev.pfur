#!/bin/bash
type=""
directory=""
echo "cin type"
read type
echo "cin directory"
read directory
echo "number of units : "
find "$directory"  -type f -name "*.$type" | wc -l
echo " units : "
find "$directory"  -type f -name "*.$type" < ls 
