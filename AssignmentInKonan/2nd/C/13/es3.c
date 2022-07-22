#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	double x,y;
	int num=0,num_in;
	while(num<5000000000){
		x = (double)(2.0*(double)rand()/((double)RAND_MAX+1.0));

		y = (double)(2.0*(double)rand()/((double)RAND_MAX+1.0));

		if ( ( sqrt((x-1.0)*(x-1.0)+(y-1.0)*(y-1.0)) )  < 1.0){num_in++;}

		num++;
	}
	printf("%.8f\n",((double)num_in/num)*4);



	return 0;
}