#!/bin/sh

#display file size in bytes: stat -c%s

for i in *
do
	echo "$i $(stat -c%s $i) bytes"
done
