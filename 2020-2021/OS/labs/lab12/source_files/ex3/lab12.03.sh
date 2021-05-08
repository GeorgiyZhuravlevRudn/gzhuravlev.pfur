#!/bin/bash
let delete=0;
while getopts c:d letter
do case $letter in
       c)create=1; arg=$OPTARG;;
       d)delete=1;; 
       *) echo WrongOption $letter
   esac
done

if((delete==0))
then for((i=1;i<=arg;i++))
     do touch ${i}.doc
     echo document №${i} has been created
     done
fi
if ((delete==1))
then for((i=1;i<=arg;i++))
     do rm ${i}.doc
     echo document №${i} has been deleted
     done
fi
