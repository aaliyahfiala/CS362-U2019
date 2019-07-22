/* -----------------------------------------------------------------------
 * Include the following lines in your makefile:
 *
 * cardtest3: cardtest3.c dominion.o rngs.o
 *      gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
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
    struct gameState* state, teststate;
    int currentPlayer; 

    printf ("TESTING endTurn():\n");
#if (NOISY_TEST == 1)
                printf("Test: checks that the players turn is over\n");
#endif
		currentPlayer = 1;
		endTurn(state);
		assert(currentPlayer == 2);
		
#if (NOIST_TEST == 1)
		printf("Test: check that hand is discarded");

		assert(state->handCount[currentPlayer] == 0);
		
#endif
    printf("All tests passed!\n");

    return 0;
}
