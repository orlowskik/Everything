#!/bin/bash

echo "Proces ID: $$"
trap 'echo Przechwycilem sygnal' 2 3 4 8

i=1

while [ $i ]
do
 echo $i
 ((i++)) 
 sleep 1
done
