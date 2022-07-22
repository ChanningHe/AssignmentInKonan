#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PAI 3.14159265358979
int main(){
	double x,y;
	int num=0,num_in;
    double redline,buleline;
    double dPAI=2*PAI;
	while(num<1000000){
		x = (int)(dPAI*(double)rand()/((double)RAND_MAX+1.0))-PAI;

		y = (int)(dPAI*(double)rand()/((double)RAND_MAX+1.0))-PAI;
        redline = cos(x)+sin(x)/2-sin(3*x);
        buleline= x/5;
        if( abs(y - buleline) < abs(redline - buleline)){
            num_in++;
        }
		//if ( ( sqrt((x-1.0)*(x-1.0)+(y-1.0)*(y-1.0)) )  < 1.0){num_in++;}
		num++;
	}
    printf("yellow count point is:%d/1000000\n",num_in);
	printf("s:%.8f\n",(double)num_in/num);



	return 0;
}