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


	
	float i=1;
	while( i <= no) {
		float sqno= pow(i, 2);
	
		if ( sqno > no ) {
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
	if ( sqno != no){
		
		while (j<=decplace){
			if ( pow(firstguess,2) > no){
				nextguess= firstguess-pow(10,-(decplace-(decplace-j)));	
				printf("Guess:%f  Square:%f\n", nextguess, pow(nextguess,2));
				if (pow(nextguess,2) > no){
					firstguess=nextguess;
				}
				else if (pow(nextguess,2) < no){
					nextguess= (firstguess+nextguess)/2;

					firstguess=nextguess;
					j++;
				}
			//	else if (pow(nextguess,2) == no){
			//		printf("Square root of %f is %f\n", no, nextguess);
			//	}

			


			}	
			else if (  pow(firstguess,2) < no){
				float nextguess= firstguess+pow(10,-(decplace-(decplace-j)));
				printf("Guess:%f Square:%f\n", nextguess, pow(nextguess,2));
				if (pow(nextguess,2) < no){
					firstguess=nextguess;
				}
				else if (pow(nextguess,2) > no){
					nextguess= (firstguess+nextguess)/2;
					firstguess=nextguess;
					j++;
				}
			//	else if (pow(nextguess,2) == no){
			//		printf("Square root of %f is %f\n", no, nextguess);
			//	}
			
			}
		}
	
	
	}
	else {
		printf("Square root of %f is %f\n", no, i);
	}
	return 0;

}
