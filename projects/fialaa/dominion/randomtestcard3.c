/**************************************************************************************
 * 				Random test for Tribute  Card
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
	int i, card, deckCount, discardCount, handPos, handCount, handPosition, deckBefore, handBefore, discardBefore;	
	int numPlayers, buysBefore, estateBefore, coinsBefore;
*	int tributeRevealedCards[2] = {-1, -1}; 
	struct gameState state, testState;
	int k[10] = {ambassador, minion, tribute, gardens, mine, remodel, smithy, village, baron, great_hall};
	int seed = 1000;
	int currentPlayer, nextPlayer;
	
	int choice;	

	srand(time(NULL));

	printf("RANDOM TEST: Tribute Card. \n");
	
	for(i = 0; i < 1000000; i++) {
		//randomize number of players, current player, and card
		numPlayers = rand() % (4 + 2);

		initializeGame(numPlayers, k, seed, &state);
		currentPlayer = rand() % 3;
		nextPlayer = currentPlayer + 1;
		card = rand() % (5 + 1);		
		for(i = 0; i < 5; i++){
			state.hand[currentPlayer][i] = card;
		}

		state.handCount[currentPlayer] = 5;
		
		memcpy(&testState, &state, sizeof(struct gameState));
		tributeCase(currentPlayer, nextPlayer, &state);		

		if ((testState.discardCount[nextPlayer] + testState.deckCount[nextPlayer]) <= 1) {
			if (testState.deckCount[nextPlayer] > 0) {
				asserttrue(testState.deckCount[nextPlayer] == state.deckCount[nextPlayer]);
			}
		}	
		else if (testState.discardCount[nextPlayer] > 0) {
			asserttrue(testState.discardCount[nextPlayer] == state.discardCount[nextPlayer]);
		} else if(testState.deckCount[nextPlayer] == 0) {
  			for (i = 0; i < state.discardCount[nextPlayer]; i++) {
				asserttrue((testState.deckCount[nextPlayer]++) == state.deckCount[nextPlayer]);
			}
		}

		
		for (i = 0; i <= 2; i++) {
			if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == gold) {//Treasure cards
				asserttrue((testState.coins + 2) == state.coins);
			} else if (tributeRevealedCards[i] == estate || tributeRevealedCards[i] == duchy || tributeRevealedCards[i] == province || tributeRevealedCards[i] == gardens || tributeRevealedCards[i] == great_hall) {//Victory Card Found
				asserttrue((testState.handCount[currentPlayer] + 2) == state.handCount[currentPlayer]);
			} else {//Action Card
				asserttrue((testState.numActions + 2) == state.numActions);
			}
		}

	}

	printf("Finished Testing Tribute Card... \n");	
	
	return 0;
}
