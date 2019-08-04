/* -----------------------------------------------------------------------
 * Include the following lines in your makefile:
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

/* TEST */
//instead of next card, checks previous card in hand
//removed game over check 

int main() {
    int seed = 1000;
    int numPlayer = 2;
    int p;
    int* k = kingdomCards(ambassador, minion, tribute, gardens, mine, remodel, smithy, village, baron, great_hall);
    struct gameState* state, teststate;
    int choice1;
    int currentPlayer; 
    int previousCard;
    // arrays of all coppers, silvers, and golds
    int estate;

    printf ("TESTING baronCase():\n");
#if (NOISY_TEST == 1)
                printf("Test: game over check\n");
#endif
                initializeGame(numPlayer, k, seed, &state); 
		memcpy(&teststate, &state, sizeof(struct gameState));
		choice1 = 1;
		estate = 0;
		currentPlayer = 0;
		baronCase(choice1, &state, currentPlayer);
                assert(supplyCount(estate, state) == 0 && isGameOver(state));

#if (NOIST_TEST == 1)
		printf("Test: iterates through the cards as expected");
#endif
	for(p = 0; p < numPlayer; p++){
                previousCard = p;
		baronCase(choice1, &state, currentPlayer);
		assert( p == previousCard++ ); 
	}
    printf("All tests passed!\n");

    return 0;
}
