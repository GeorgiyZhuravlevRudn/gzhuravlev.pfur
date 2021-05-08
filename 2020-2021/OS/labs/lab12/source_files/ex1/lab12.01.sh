#!/bin/bash
while getopts i:o:p:Cn letter
do case $letter in
       i) i=1; iarg=$OPTARG;;
       o) o=1; oarg=$OPTARG;;
       p) p=1; parg=$OPTARG;;
       C) C=1;;
       n) n=1;;
       *) echo wrongoption $letter
  esac
done
	  if(((C==1)&&(n==1)))
	  then grep -e${parg} -i -n ${iarg}
	       if((o==1))
	       then grep -e${parg} -i -n ${iarg} > ${oarg}
	       fi
	  fi
	  if(((C==1)&&(n==0)))
	  then grep -e${parg} -i -n ${iarg}
	       if((o==1))
	       then grep -e${parg} -i ${iarg} > ${oarg}
	       fi
	  fi
	  if(((C==0)&&(n==1)))
	  then grep -e${parg} -i -n ${iarg}
	       if((o==1))
	       then grep -e${parg} -n ${iarg} > ${oarg}
	       fi
	  fi
	  if(((C==0)&&(n==0)))
	  then grep -e${parg} -i -n ${iarg}
	       if((o==1))
	       then grep -e${parg}  ${iarg} > ${oarg}
	       fi
	  fi
		   
	     
