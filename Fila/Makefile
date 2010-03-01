all: s e Time Men
	g++ -Wall -c *.h

s: SeqFila.h SeqFilaTes.cpp
	g++ -Wall -g SeqFilaTes.cpp -o SeqFilaTes

e: EncFila.h EncFilaTes.cpp
	g++ -Wall -g EncFilaTes.cpp -o EncFilaTes

Time: Time.cpp EncFila.h SeqFila.h
	g++ -Wall -g Time.cpp -o Time

Men: Mem.cpp EncFila.h
	g++ -Wall -g Mem.cpp -o Mem

clean:
	rm -v -f SeqFilaTes SeqFilaTes.ghc EncFilaTes EncFilaTes.ghc Time *.gch
	rm -v *.backup*
