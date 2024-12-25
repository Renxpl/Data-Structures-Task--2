hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/Agac.o -c ./src/Agac.cpp
	g++ -I ./include/ -o ./lib/BagliListe.o -c ./src/BagliListe.cpp
	g++ -I ./include/ -o ./lib/ListeGezici.o -c ./src/ListeGezici.cpp
	g++ -I ./include/ -o ./lib/KuyrukDugum.o -c ./src/KuyrukDugum.cpp
	g++ -I ./include/ -o ./lib/Kuyruk.o -c ./src/Kuyruk.cpp	
	g++ -I ./include/ -o ./bin/Deneme.exe  ./lib/Dugum.o ./lib/Agac.o  ./lib/BagliListe.o ./lib/ListeGezici.o  ./lib/KuyrukDugum.o ./lib/Kuyruk.o ./src/main.cpp

calistir:
	./bin/Deneme.exe