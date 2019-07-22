/* -----------------------------------------------------------------------
 * Include the following lines in your makefile:
 *
 * unittest4: unittest4.c dominion.o rngs.o
 *      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define NOISY_TEST 1


int main() {
    int seed = 1000;
    int numPlayer = 2;
    int p;
    int* k = kingdomCards(ambassador, minion, tribute, gardens, mine, remodel, smithy, village, baron, great_hall);
    struct gameState* state, teststate;
    int choice1;
    int currentPlayer; 
    int nextPlayer;
    int previousCard;
    int estate;

    printf ("TESTING tributeCase():\n");
#if (NOISY_TEST == 1)
                printf("Test: checks that other player discards card\n");
#endif
                initializeGame(numPlayer, k, seed, &state); 
		memcpy(&teststate, &state, sizeof(struct gameState));
		choice1 = 1;
		estate = 0;
		currentPlayer = 0;
		nextPlayer = currentPlayer++;
		state->deckCount[nextPlayer] = 2;
		tributeCase(currentPlayer, nextPlayer, &state);
                assert(state->deckCount[nextPlayer] = 1);

#if (NOIST_TEST == 1)
		printf("Test: checks that the players turn quits as expected");
#endif
		assert(tributeCase(currentPlayer, nextPlayer, &state) = 0);
    	
#if (NOIST_TEST == 1)
		printf("Test: Shuffled Deck ");
#endif
		int tempPlayer = currentPlayer;
		bool shuffle = false;
		tributeCase(currentPlayer, nextPlayer, &state);
		for(int i = 0; i < state->deckCount[currentPlayer]; i++) { //puts all cards into the temp deck
			for(int j = 1; j < state->deckCount[currentPlayer]; j++) {
				deck[tempPlayer][i] = deck[currentPlayer][j];
			}
		}
		for (i = 0; i < state->deckCount[currentPlayer]; i++) {
			for( j = 1; j < state->deckCount[currentPlayer]; j++) {
				i++;
				if (deck[currentPlayer][i] != deck[tempPlayer][j]){
					shuffle = true;
				}
				else 	shuffle = false;
			}
		}
		assert(shuffle == true);



	printf("All tests passed!\n");

    return 0;
}
