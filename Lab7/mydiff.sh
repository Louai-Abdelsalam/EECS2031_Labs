#!/bin/sh

exitStatus=0

if test $# -ne 2
then
	echo "need 2 arguments"
	exit 1
elif test -d $1 || test -d $2
then
	echo "No directories please"
	exit 1
fi

if test ! -e $1
then
	echo "${1}: no such file"
 	exitStatus=1
fi
if test ! -e $2
then
	echo "${2}: no such file"
	exitStatus=1
fi

if test $exitStatus -eq 1
then
	exit 1
fi

if test "$(cat $1)" = "$(cat $2)" 
then
	echo "The two files are identical"
else
	echo "The two files are not identical"
fi 
