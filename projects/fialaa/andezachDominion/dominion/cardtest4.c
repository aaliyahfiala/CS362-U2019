/* -----------------------------------------------------------------------
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
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
    int numPlayer = 2;
    struct gameState* state, teststate;
    int currentPlayer; 
    int highscore;
    int * players;

    printf ("TESTING getWinners():\n");
#if (NOISY_TEST == 1)
                printf("Test: chooses winner\n");
#endif
		players[0] = 0;
		players[1] = 100;
		getWinners(players(numPlayer), &state);
		assert(players[1] == 1 && players[0] == 0);

    printf("All tests passed!\n");

    return 0;
}
