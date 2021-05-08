#!/bin/bash
Words=
echo number of random words:
read Words
for((i=0;i<$Words;i++))
do   echo $RANDOM | tr '[0-32670]' '[a-z]'
done
