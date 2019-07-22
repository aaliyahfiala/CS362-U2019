/* -----------------------------------------------------------------------
 * Include the following lines in your makefile:
 *
 * unittest3: unittest3.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
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
//check choices
//check that function ends 

int main() {
    int seed = 1000;
    int numPlayer = 2;
    int p;
    int* k = kingdomCards(ambassador, minion, tribute, gardens, mine, remodel, smithy, village, baron, great_hall);
    struct gameState* state, teststate;
    int choice1, choice2;
    int currentPlayer; 
    int previousCard;
    int estate;

    printf ("TESTING ambassadorCase():\n");
#if (NOISY_TEST == 1)
                printf("Test: player choices are within bounds\n");
#endif
                initializeGame(numPlayer, k, seed, &state); 
		memcpy(&teststate, &state, sizeof(struct gameState));
		choice1 = 0;
		choice2 = 10;
		estate = 0;
		currentPlayer = 0;
		assert(ambassadorCase(choice1, choice2, p, &state, currentPlayer) != -1);

#if (NOIST_TEST == 1)
		printf("Test: turn executes normally when no errors occur.");
#endif	
		choice2 = 0;	
    		assert(ambassadorCase(choice1, choice2, p, &state, currentPlayer) = 0);

	printf("All tests passed!\n");

    return 0;
}
