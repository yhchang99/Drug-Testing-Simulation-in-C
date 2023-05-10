#include <stdlib.h>
#include <stdio.h>											
#include <time.h>						

// Define starting parameters of simulation
#define DRUG_1_CURE_RATE		0.6		// cure rate of drug 1
#define DRUG_2_CURE_RATE	    0.4		// cure rate of drug 2
#define M						10      // M is the number of cures needed to stop the test
#define NUM_GAMES 				10000  	// Number of tests until reach condition M

// Define color commands
#define RESET 					"\x1b[0m"
#define BOLD					"\x1b[1m"
#define F_RED					"\x1b[31m"
#define F_GREEN					"\x1b[32m"

int main()
{
	// Display game parameters
	printf( "Drug Testing Parameters:\n"
			"    Drug 1 cure rate:        %0.2f\n"
			"    Drug 2 cure rate:        %0.2f\n"
			"    test stop at M :           %d\n",
			DRUG_1_CURE_RATE, DRUG_2_CURE_RATE, M);
	srand( time(NULL) );
	// Track average number of rounds it takes to get to M
	int totalRounds = 0;
    int totalDrug1Cure = 0, totalDrug2Cure = 0;

	for(int i = 0; i < NUM_GAMES; i++ ){
        // Track number of cures and not cures for each person
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
		totalRounds += round;
        totalDrug1Cure += Drug1Cure;
        totalDrug2Cure += Drug2Cure;
	}

	// Calculate average number of rounds by dividing sum by the number of test
	float averageRounds  = totalRounds / NUM_GAMES;
	// Display the results of the simulation
	printf( "%110sAverage number of rounds needed: %.2f.\n"
			"Results:\n"
			"    " BOLD "%sDrug1" RESET ":   %.4f%%\n"
			"    " BOLD "%sDrug2" RESET ":   %.4f%%\n",
			"\n", averageRounds, 
			totalDrug1Cure < totalDrug2Cure ? F_RED : F_GREEN,
            100 * (float) totalDrug1Cure/totalRounds, 
			totalDrug2Cure < totalDrug1Cure ? F_RED : F_GREEN,
			100 * (float) totalDrug2Cure/totalRounds);
	return 0;
} 