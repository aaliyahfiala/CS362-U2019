/**************************************************************************************
 * 				Random test for Minion Card
 * Aaliyah Fiala
 * CS 362 Assignment 4
 * 7/28/2019
 *
 * ************************************************************************************/				

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

void asserttrue(int boolean) {
	if(boolean) {
		printf("PASSED");
	} else {
		printf("FAILED");
	}
}

int main() {
	int i, deckCount, discardCount, handCount, handPos, deckBefore, handBefore, discardBefore;	
	int actionBefore, coinsBefore;

	struct gameState state, testState;
	int k[10] = {ambassador, minion, tribute, gardens, mine, remodel, smithy, village, baron, great_hall};
	int seed = 1000;
	int currentPlayer = 0;
	
	int choice1, choice2;	

	srand(time(NULL));

	printf("\nRANDOM TEST: Minion Card. \n");
	
	for(i = 0; i < 1000000; i++) {
		initializeGame(2, k, seed, &state);
		deckCount = rand() % (MAX_DECK + 1);	
		handCount = rand() % (deckCount + 1);
		handPos = 0;	
		memcpy(&testState, &state, sizeof(struct gameState));
		choice1 = rand() % 2;
		choice2 = rand() % 2;
				
		actionBefore = testState.numActions;
		coinsBefore = testState.coins;

		minionCase(choice1, choice2, currentPlayer, handPos, &state);
			
		//check that number of actions increased by one
		asserttrue((actionBefore + 1) == state.numActions);	
		
		if(choice1){
			//check that the number of buys increases by one
			asserttrue((coinsBefore + 2) == state.coins);
		} else if(choice2) {
			asserttrue(state.handCount == 4);
		}
		
		minionCase(0, 1, currentPlayer, handPos, &state);	
	}
	printf("\nFinished Testing Minion Card... \n");	
	
	return 0;
}
