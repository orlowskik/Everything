#!/bin/bash

for i in $@
do
 if [ -d "$i" ]
  then 
    x=$(ls $i | wc -l)
    liczba=1
    if [ $x -ge $liczba ]
     then
      echo "Katalog $i nie jest pusty"
     else
      echo "Katalog $i jest pusty"
    fi
 elif [ -f "$i" ]
  then 
   echo "Plik $i istnieje"
 else
   echo "Nie istnieje podany plik ani katalog $i"
fi
done




