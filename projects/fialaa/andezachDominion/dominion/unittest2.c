/* -----------------------------------------------------------------------
 * Include the following lines in your makefile:
 *
 * unittest2: unittest2.c dominion.o rngs.o
 *      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
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
//check # of coins
//check the currect player 

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int* k = kingdomCards(ambassador, minion, tribute, gardens, mine, remodel, smithy, village, baron, great_hall);
    struct gameState G;
    int choice1, choice2;
    int maxHandCount = 5;
    int currentPlayer; 
    int handpos;

    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    int estate;
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf ("TESTING baronCase():\n");
#if (NOISY_TEST == 1)
                printf("Test player %d's number of coins.\n", p);
#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G->handCount[p] = handCount;                 // set the number of cards on hand
		G->coins = 0;
		choice1 = 1;
		choice2 = 0;
		minionCase(choice1, choice2, currentPlayer, p, &G);
                assert(G->coins == 2);

#if (NOIST_TEST == 1)
		printf("Test player %d drew four cards.", p);
#endif	
		choice1 = 0;
		choice2 = 1;
		int prevhandCount = handCount;
		minionCase(choice1, choice2, currentPlayer, p, &G);
		assert(handCount == prevhandCount + 4 ); 

    printf("All tests passed!\n");

    return 0;
}
