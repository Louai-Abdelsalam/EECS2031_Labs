#!/bin/sh
#permission xyz; x for file owner, y is for the group, z is for everyone else
# x, y, and z values can be the following:
# 7(means reading, writing, and execution rights)
# 6(means reading and writing rights)
# 5(means reading and execution rights)
# 4(means reading only rights)
# 3(means writing and executing rights)
# 2(means writing only rights)
# 1(means execution only rights)
# 0(no rights to the file at all)

# chmod is a system call that sets/changes access permissions to the file

# so, command to set access permissions to shell files is "chmod xyz [file name]"

echo "Hello World"
first="Louai"
last="Abdelsalam"

echo "Hello World, my name is ${first} ${last}."

dir=/eecs/home/louai/Desktop/
echo $dir
ls $dir









