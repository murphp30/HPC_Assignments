#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void exit(int status);

int main( int argc, char *argv[] ) {

	if (argv[1]==NULL){
		printf("Please input number to find square root of\n");
		exit(0);
	}
	if (argv[2]==NULL){
		printf("Please input number of decimal places\n");
		exit(0);
	}

	float no= atof(argv[1]);
	int decplace=atoi(argv[2]);
	printf("Search for square root of %f to %d decimal places\n", no, decplace);


	if( decplace > 6){
		printf("Too many decimal places. Try fewer than 6\n");
		exit(0);
	}
	//calculate a first guess
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
	float firstguess= (i+(i-1))/2;

//iterate through more guesses
	
	float nextguess;
	int j=1;
	while(j <= decplace){
		if ( pow(firstguess, 2) > no){
		//	printf("First guess %f\n",firstguess);
			firstguess=firstguess-pow(10, -j);
			nextguess=firstguess;
			if (pow(nextguess,2) < no){
				firstguess=(firstguess+nextguess)/2;
// this doesn't actually do anything because for some reason variables assigned in
// an if statement may as well not exist. 
//			printf("New guess %f\n", firstguess);
				j++;
			}
		
		}


		else if ( pow(firstguess, 2) < no){
		//	printf("First guess %f\n",firstguess);
			firstguess=firstguess+pow(10, -j);
			nextguess=firstguess;
			if (pow(nextguess,2) > no){
				firstguess=(firstguess+nextguess)/2;
//			printf("New guess %f\n", firstguess);
				j++;
			}
		
		}
	
	}
	
	
	
	printf("Square root of %f is %f, including rounding errors\n",no, firstguess);
	
	
			
	return 0;

}
