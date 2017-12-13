#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main( int argc, char *argv[] )
{
	double arg1= atoi(argv[1]);	
	printf("number: %f \n", arg1);

	double j;
	double k;

	for(j=1.0; j<=arg1; j++){
		double rtj= sqrt(j);

		for(k=1.0; k<=arg1; k++){

			double T=k*(k+1)/2;

			if( j==T && rtj-(int)rtj==0){
				printf("%d is a triangle number and a square number :)\n",(int)j);
				break;
			}
			else if (T>j && rtj-(int)rtj==0){
				printf("%d is not a triangle number but is a square number :/\n",(int)j);
				break;
		
			}		
			else if ( j==T && rtj-(int)rtj!=0){
				printf("%d is a triangle number but not a square number :/\n",(int)j);
				break;
			}
			else if (T>j && rtj-(int)rtj!=0){
				printf("%d is not a triangle number or a square number :(\n",(int)j);
				break;
			}
		
		}
	}
	return 0;
}
