all:
	g++ -c PilhaSeq.h
	g++ -c PilhaEnc.h

s: PilhaSeq.h Ponto2D_Seq.cpp
	g++ -g Ponto2D_Seq.cpp -o Ponto2D_Seq

e: PilhaEnc.h Ponto2D_Enc.cpp
	g++ -g Ponto2D_Enc.cpp -o Ponto2D_Enc

calc: PilhaEnc.h Calc.cpp
	clear
	g++ -Wall -g Calc.cpp -o Calc

kalc: PilhaEnc.h Kalc.cpp
	g++ -Wall -g Kalc.cpp -o Kalc

eq:
	g++ -Wall -g Eq.cpp -o Eq

clear:
	rm -f Calc Kalc *.gch *.backup *~ Ponto2D_Enc Ponto2D_Seq Eq
