/* -----------------------------------------------------------------------
 * Include the following lines in your makefile:
 *
 * cardtest2: cardtest2.c dominion.o rngs.o
 *      gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
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
    int player; 

    printf ("TESTING shuffle():\n");
#if (NOISY_TEST == 1)
                printf("Test: The number of cards is constant. \n");
#endif
		int deckCountPrev = state->deckCount[player];
		shuffle(player, state);
		assert(state->deckCount[player] == deckCountPrev);
#if (NOISY_TEST == 1)
                printf("Test: The deck is shuffled. \n");
#endif
		for (int j = 0; j < state->deckCount[player]; j++) {
			int* card = deck[player][j];
		}
		
		shuffle(player, state);
	
		for (int i = 0; i < state->deckCount[player]; i++) {
			assert(card[player][i] != state->deck[player][i];
		}
					

    printf("All tests passed!\n");

    return 0;
}
