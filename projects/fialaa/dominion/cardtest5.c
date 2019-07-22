/* -----------------------------------------------------------------------
 * Include the following lines in your makefile:
 *
 * cardtest5: cardtest5.c dominion.o rngs.o
 *      gcc -o cardtest5 -g  cardtest5.c dominion.o rngs.o $(CFLAGS)
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
    int cardTemp;

    printf ("TESTING drawCard():\n");
#if (NOISY_TEST == 1)
                printf("Test: the number of cards in the players hand increments\n");
#endif
	cardTemp = state->deckCount[currentPlayer];
	drawCard(currentPlayer, state);
	assert(cardTemp == state->deckCount[currentPlayer]++);
    


	printf("All tests passed!\n");

    return 0;
}
