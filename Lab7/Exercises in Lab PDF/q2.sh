#!/bin/sh

#substring extraction: expr substr $string $position $length
#display all files and their permissions: ls -l $string

for i in *
do
	#echo $(expr substr "$(ls -l $i)" 3 1)
	if test $(expr substr "$(ls -l $i)" 3 1) = "w" 
	then
		echo $i
	fi
done
