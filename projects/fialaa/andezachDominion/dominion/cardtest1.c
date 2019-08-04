/* -----------------------------------------------------------------------
 * Include the following lines in your makefile:
 *
 * cardtest1: cardtest1.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
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
    int* k = kingdomCards(ambassador, minion, tribute, gardens, mine, remodel, smithy, village, baron, great_hall);
    struct gameState* state, teststate;
    int numPlayers;

    printf ("TESTING intializeGame():\n");

#if (NOISY_TEST == 1)
                printf("Test: check that there are two players\n");
#endif
		numPlayers = 0;
		initializaeGame(numPlayers, k, seed, state);
		assert(numPlayers == 2);

    printf("All tests passed!\n");

    return 0;
}
