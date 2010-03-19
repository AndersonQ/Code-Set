#include <map>
#include <iostream>
#include "timer.h"

int main () {
	std::map<unsigned int, std::map<unsigned int, std::map<unsigned int, double> > > mat;
	unsigned a, i, j, k;
	double x = 9.3;

	Timer t;

	for (a=0; a<10; a++)
		for (i=1; i<90; i++)
			for (j=1; j<90; j++)
				for (k=0; k<90; k++)
					mat[i][j][k] = x;
	std::cout << "1\n";
	t.start();
	for (a=0; a<10; a++)
                for (i=1; i<90; i++)
                        for (j=1; j<90; j++)
                                for (k=0; k<90; k++)
                                        mat[i][j][k] = x;
	t.stop();
	std::cout << "Elapsed time (SET): "
	          << t.elapsed_time()
		  << " seconds\n";

	t.reset();
        t.start();
        for (a=0; a<10; a++)
                for (i=1; i<90; i++)
                        for (j=1; j<90; j++)
                                for (k=0; k<90; k++)
                                        x = mat[i][j][k] = x;
        t.stop();
        std::cout << "Elapsed time (GET): "
                  << t.elapsed_time()
                  << " seconds\n";

}
