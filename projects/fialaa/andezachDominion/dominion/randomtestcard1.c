/**************************************************************************************
 * 				Random test for Baron Card
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
	int i, deckCount, discardCount, handPos, handCount, handPosition, deckBefore, handBefore, discardBefore;	
	int buysBefore, estateBefore, coinsBefore;

	struct gameState state, testState;
	int k[10] = {ambassador, minion, tribute, gardens, mine, remodel, smithy, village, baron, great_hall};
	int seed = 1000;
	int currentPlayer = 0;
	
	int choice;	

	srand(time(NULL));

	printf("RANDOM TEST: Baron Card. \n");
	
	for(i = 0; i < 1000000; i++) {
		initializeGame(2, k, seed, &state);
		deckCount = rand() % (MAX_DECK + 1);	
		handCount = rand() % (deckCount + 1);
		
		memcpy(&testState, &state, sizeof(struct gameState));
		
		testState.supplyCount[estate] = rand() % (8 + 1);
		
		buysBefore = state.numBuys;
		estateBefore = testState.supplyCount[estate];	
		coinsBefore = testState.coins;
			

		baronCase(0, &state, currentPlayer);
			
		//check that the number of buys increases by one
		asserttrue((buysBefore + 1) == state.numBuys);

		//check that the number of players estates are incremented, and the total is decremented
		if(supplyCount(estate, &testState) > 0){
			asserttrue((estateBefore + 1) == state.supplyCount[estate]);
		}

		baronCase(1, &state, currentPlayer);

		//check that the number of buys increases by one
		asserttrue((buysBefore + 1) == (state.numBuys - 1));


		//check that an estate is discarded and that gained 4 coins
		asserttrue((estateBefore - 1) == state.supplyCount[estate]);
		asserttrue((coinsBefore + 4) == state.coins);
	
	}
	printf("Finished Testing Baron Card... \n");	
	
	return 0;
}
