all: s e Tempo Men
	g++ -Wall -c *.h

s: SeqFila.h SeqFilaTes.cpp
	g++ -Wall -g SeqFilaTes.cpp -o SeqFilaTes

e: EncFila.h EncFilaTes.cpp
	g++ -Wall -g EncFilaTes.cpp -o EncFilaTes

Tempo: Tempo.cpp EncFila.h SeqFila.h Timer.cpp
	g++ -Wall -g Tempo.cpp -o Tempo

Men: Mem.cpp EncFila.h
	g++ -Wall -g Mem.cpp -o Mem

clean:
	rm -v -f SeqFilaTes SeqFilaTes.ghc EncFilaTes EncFilaTes.ghc Tempo Mem *.gch
	rm -v *.backup*
