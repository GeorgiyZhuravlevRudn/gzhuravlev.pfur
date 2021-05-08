#!/bin/bash
lockfile="./lockfile"
echo name of the file:
exec {fn} > $lockfile
echo "locked"
until flock -n ${fn}
do
    echo "not locked"
    sleep 0.05m
    flock -n ${fn}
done
t1= 
echo time:
read t1
for(( i=o; i<=t1; i++))
do
    echo "working"
    sleep 0.05m
done
