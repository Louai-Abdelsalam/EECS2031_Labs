#!/bin/sh

if test $# -ne 4
then
        echo "Wrong Arguments"
        exit 1
else
        count=1
	line_count=$(wc -l < $1)
        
	if test $3 = "-check"
        then
                while test $count -le $line_count 
                do
			if test $(head -$count $1 | tail -1 | awk '{print $2}') -lt $4
			then
				grep -w "$(head -$count $1 | tail -1 | awk '{print $1}')" $2
			fi
		
			count=$(expr $count + 1)
		done
        elif test $3 = "-show"
        then
		stock=$(grep -w "$4" $1 | awk '{print $2}')
		price=$(grep -w "$4" $2 | awk '{print $2}')
		echo "$stock * $price" | bc	
	fi
fi
