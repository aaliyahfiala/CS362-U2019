/* -----------------------------------------------------------------------
 * Include the following lines in your makefile:
 *
 * unittest5: unittest5.c dominion.o rngs.o
 *      gcc -o unittest5 -g  unittest5.c dominion.o rngs.o $(CFLAGS)
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

int main() {
    int seed = 1000;
    int numPlayer = 2;
    int p;
    int* k = kingdomCards(ambassador, minion, tribute, gardens, mine, remodel, smithy, village, baron, great_hall);
    struct gameState* state, teststate;
    int choice1, choice2;
    int currentPlayer; 
    int handPos = 0;
    
	printf ("TESTING mineCase():\n");
#if (NOISY_TEST == 1)
                printf("Test: check bounds\n");
#endif
                initializeGame(numPlayer, k, seed, &state); 
		memcpy(&teststate, &state, sizeof(struct gameState));
		choice1 = 1;
		choice2 = treasure_map + 1;
		currentPlayer = 0;
		assert(mineCase(choice1, choice2, currentPlayer, handPos,  &state) == -1);

#if (NOIST_TEST == 1)
		printf("Test: check number of cards discarded");
#endif
		choice1 = 1;
		choice2 = 1;
		state->handCount[currentPlayer] = 2;
		mineCase(choice1, choice2, currentPlayer, handPos, &state);
		assert(state->handCount[currentPlayer] = 1);

    printf("All tests passed!\n");

    return 0;
}
