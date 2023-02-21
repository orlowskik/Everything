#!/bin/bash
 
case $1 in
  -a)
	liczba=$(ls -a -1 | wc -l)
	echo "Jest $liczba plikow i katalogow";;
   *)
	liczba=$(ls -1 | wc -l)
        echo "Jest $liczba plikow i katalogow nieukrytych";;
esac


