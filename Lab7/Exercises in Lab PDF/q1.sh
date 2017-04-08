#!/bin/sh

if test $# -ne 2
then
	echo "shell_script_name: needs two parameters"
else
	echo "$(expr $1 + $2)"
fi
