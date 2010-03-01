#include <sys/types.h>
#include <unistd.h>

	main()
	{
	   int i;
	   int n = 10;
	   pid_t val;
 
	   if(val = fork())
	     for(i=1; i < n; i++) 
 	       {
		  sleep(random()%3); printf("=====> i: %d\n",i);
 	       }
          else
            for(i=n; i >0; i--) 
               {
         	  sleep(random()%3); printf("==============> i: %d\n",i);
               }
	}
