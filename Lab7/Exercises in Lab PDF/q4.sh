#!/bin/sh

#display time in h:m:s format: date +%Y

echo -n "What is your full name? "
read name 
echo "Hello, $name"
echo -n "What is your year of birth? "
read birthYear
echo "Oh, you are $(expr $(date +%Y) - $birthYear) years old"
echo -n "What is your login name? "
read login
echo "$(grep $login /etc/passwd)"
