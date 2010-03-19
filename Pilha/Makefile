all: s e kalc eq
	g++ -c PilhaSeq.h
	g++ -c PilhaEnc.h

s: PilhaSeq.h Ponto2D_Seq.cpp
	g++ -g Ponto2D_Seq.cpp -o Ponto2D_Seq

e: PilhaEnc.h Ponto2D_Enc.cpp
	g++ -g Ponto2D_Enc.cpp -o Ponto2D_Enc

calc: PilhaEnc.h Calc.cpp
	clear
	g++ -Wall -g Calc.cpp -o Calc

kalc: PilhaEnc.h kalc.cpp
	g++ -Wall -g kalc.cpp -o Kalc

eq: PilhaEnc.h eq.cpp
	g++ -Wall -g eq.cpp -o Eq

flood: PilhaEnc.h floodFill.cpp
	g++ -Wall -g floodFill.cpp -o FloodFill.cpp

clear:
	rm -v -f Calc Kalc *.gch *.backup *~ Ponto2D_Enc Ponto2D_Seq Eq
