#!/bin/bash



wymiar=300;		# zmienne wymagane do pracy programu
archiwum=zdj.tar;
zastap=1;

echo Podaj sciezke do skopiowania plikow;	
read sciezka;		# wczytanie sciezki do zdjec

cp $sciezka/*.JPEG ./;	# kopiowanie plikow JPEG do aktualnego folderu
cp $sciezka/*.PNG ./;	# kopiowanie plikow PNG do aktualnego folderu

for file1 in *.JPEG;	# petla operacji na plikach JPEG
do	
	zmiana=`basename "$file1" .JPEG | tr ' ' '_'`; # ustawienie zmiennej dla nowej nazwy pliku (usuwanie spacji)
	mv "$file1" $zmiana.jpeg;			 # zmiana rozszerzenia na pisane z malych liter 
	convert $zmiana.jpeg -resize $wymiar $zmiana.jpeg; #zmiana rozmiaru obrazu
	
	#  dodawanie tylko kopiowanych plikow do archiwum
	if [ $zastap -eq 1 ]	# warunek tworzenia nowego archiwum ( jezeli juz istnieje to zamienia )
	then
		tar -cf $archiwum $zmiana.jpeg;
		zastap=0;
	else
		tar -rf $archiwum $zmiana.jpeg; # dodawanie plikow do archiwum
	fi
	
	rm $zmiana.jpeg;	# usuwanie plikow z folderu ( sa w archiwum, nie ma sensu zajmowac wiecej miejsca )
	
done

for file2 in *.PNG;	# analogiczne operacje dla plikow PNG
do
	zmiana=`basename "$file2" .PNG | tr ' ' '_'`;
	mv "$file2" $zmiana.png;
	convert $zmiana.png -resize $wymiar $zmiana.png;
	tar -rf $archiwum $zmiana.png;	# dopisanie plikow png do archiwum
	rm $zmiana.png;
done









