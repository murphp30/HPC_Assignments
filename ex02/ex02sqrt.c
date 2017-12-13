#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main( int argc, char *argv[] ) {

	float no= atof(argv[1]);
	int decplace=atoi(argv[2]);
	printf("Search for square root of %f to %d decimal places\n", no, decplace);


	float newPrecision(float n, float i)
	{
		 return floor(pow(10,i)*n)/pow(10,i);
	}	

	//find first guess

	
	float i=1;
	while( i <= no) {
//	printf("i   = %f\n",i);
		float sqno= pow(i, 2);
//	printf("i^2 = %f\n", sqno);
	
		if ( sqno > no ) {
//			printf("First guess is between %f and %f\n", i-1,i);
			break;
		}
		else if ( sqno == no) {
				break;
		}

	i++;	
	}
	float sqno= pow(i, 2);
	float firstguess= (i+(i-1))/2;

	int j=1;
	float nextguess;
//	printf("First guess: %f\n", firstguess);
	if ( sqno != no){
	//	for( j=1; j<=decplace; j++){
		
		while (j<=decplace){
			//printf ("Square of %f yields %f\n",firstguess, pow(firstguess,2));
			if ( pow(firstguess,2) > no){
//				printf("Square of %f=%f, Too high\n", firstguess, pow(firstguess,2));
							
				nextguess= firstguess-pow(10,-(decplace-(decplace-j)));	
//				printf("Next guess: %f\n", nextguess);
				//printf("Square of %f is %f\n", nextguess, pow(nextguess,2);

				if (pow(nextguess,2) > no){
//					printf("Square of %f=%f, still too high\n", nextguess, pow(nextguess,2));
					firstguess=nextguess;
//					printf("Next guess: %f\n", nextguess);

				//	j--;
				}
				else if (pow(nextguess,2) < no){
					nextguess= (firstguess+nextguess)/2;
//					printf("Square of %f=%f too low now\n",nextguess, pow(nextguess,2));
				//	printf("Next guess is %f\n", nextguess);
				
//					printf("Next guess: %f\n", nextguess);

					firstguess=nextguess;
					j++;
				}
			//	else if (pow(nextguess,2) == no){
			//		printf("Square root of %f is %f\n", no, nextguess);
			//	}

			


			}	
			else if (  pow(firstguess,2) < no){
//				printf("Square of %f=%f, Too low\n", firstguess, pow(firstguess,2));
				float nextguess= firstguess+pow(10,-(decplace-(decplace-j)));
			
//				printf("Next guess: %f\n", nextguess);
//				printf("Next guess is %f\n", nextguess);
				if (pow(nextguess,2) < no){
					firstguess=nextguess;
//					printf("Next guess: %f\n", nextguess);
//					printf("Square of %f=%f, still too low\n", nextguess, pow(nextguess,2));
					//j--;
				}
				else if (pow(nextguess,2) > no){
					nextguess= (firstguess+nextguess)/2;
//					printf("Square of %f=%f too high now\n",nextguess, pow(nextguess,2));
//					printf("Next guess: %f\n", nextguess);
					firstguess=nextguess;
					j++;
				}
			//	else if (pow(nextguess,2) == no){
			//		printf("Square root of %f is %f\n", no, nextguess);
			//	}
				//printf("Next guess is %f\n", nextguess);
			
			}
		}
	
	
	}
	else {
		printf("Square root of %f is %f\n", no, i);
	}
//	float num=5.0;
//	printf("%f to %d decimal places is %f\n", num, decplace, newPrecision(num, decplace));
	return 0;

}
