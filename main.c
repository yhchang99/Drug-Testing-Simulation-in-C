#include <stdlib.h>
#include <stdio.h>											
#include <time.h>						

// Define starting parameters of simulation
#define DRUG_1_CURE_RATE		0.9		// cure rate of drug 1
#define DRUG_2_CURE_RATE	    0.5		// cure rate of drug 2
#define NUM_TESTS 				10000  	// Number of tests until reach condition M
// Define color commands
#define RESET 					"\x1b[0m"
#define BOLD					"\x1b[1m"
#define F_RED					"\x1b[31m"
#define F_GREEN					"\x1b[32m"

int main()
{
	printf( "***********************************************\n");
	FILE * fp = fopen( "data.dat", "w" );
	// Display game parameters
	for(int M = 1;M<15;M++){
		printf( "Drug Testing Parameters:\n"
				"    Drug 1 cure rate:        %0.2f\n"
				"    Drug 2 cure rate:        %0.2f\n"
				"    test stop at M :           %d\n",
				DRUG_1_CURE_RATE, DRUG_2_CURE_RATE, M);
		srand( time(NULL) );
		// Track average number of rounds it takes to get to M
		int totalRounds = 0;
		int totalDrug1Cure = 0, totalDrug2Cure = 0;
		for(int i = 0; i < NUM_TESTS; i++ ){
			int Drug1Cure = 0, Drug1NotCure = 0;
			int Drug2Cure = 0, Drug2NotCure = 0;
			double rate1 = DRUG_1_CURE_RATE;
			double rate2 = DRUG_2_CURE_RATE;
			int round = 0;
			while( Drug1Cure-Drug2Cure < M && Drug1Cure - Drug2Cure > -M){
				double outcome1 = (double) rand() / (RAND_MAX + 1.0);
				outcome1 < rate1? Drug1Cure++ : Drug1NotCure++;
				double outcome2 = (double) rand() / (RAND_MAX + 1.0);
				outcome2 < rate2? Drug2Cure++ : Drug2NotCure++;
				round++;
			}
			Drug1Cure-Drug2Cure > 0 ? totalDrug1Cure++ : totalDrug2Cure++;
			totalRounds += round;
		}
		float averageRounds  = totalRounds / NUM_TESTS;
		printf( "%110sAverage number of rounds needed: %.2f.\n"
				"Results:\n"
				"    " BOLD "%sDrug1 finish the test with prob" RESET ":   %.4f%%\n"
				"    " BOLD "%sDrug2 finish the test with prob" RESET ":   %.4f%%\n",
				"\n", averageRounds, 
				totalDrug1Cure < totalDrug2Cure ? F_RED : F_GREEN,
				100 * (float) totalDrug1Cure/NUM_TESTS , 
				totalDrug2Cure < totalDrug1Cure ? F_RED : F_GREEN,
				100 * (float) totalDrug2Cure/NUM_TESTS );
		printf( "***********************************************\n");
		fprintf( fp, "%d %f\n",M,(float) totalDrug2Cure/NUM_TESTS);
		
	}
	return 0;
} 