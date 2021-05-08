#!/bin/bash
for something in *
do if test -d $something
   then echo $something - directory
   else echo -n $something - file, you can: 
   	if test -r $something
	then echo read
	else echo -
	fi
	if test -w $something
	then echo write
	else echo -
	fi
	if test -x $something
	then echo execute
	else echo - 
	fi
    fi
done
