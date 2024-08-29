#include <stdio.h>

// Bubble sort algorithm for coin combinations
void bubbleSort(int combos[][4], int numCombos){
    // VARIABLES
    int i; // Outer loop control variable
    int j; // Inner loop control variable
    int k; // Swapping loop control variable
    int iTotalCoins; // Total coins for ith value in array
    int jTotalCoins; // Total coins for jth value in array
    int temp; // Temporary variable for swapping values

    // EXECUTABLE STATEMENTS
    for(i = 0; i < numCombos - 1; i++){
        for(j = i + 1; j < numCombos; j++){
            iTotalCoins = combos[i][0] + combos[i][1] + combos[i][2] + combos[i][3];
            jTotalCoins = combos[j][0] + combos[j][1] + combos[j][2] + combos[j][3];

            // Check to see if combinations should be swapped
            if(iTotalCoins > jTotalCoins){
                for(k = 0; k < 4; k++){
                    temp = combos[i][k];
                    combos[i][k] = combos[j][k];
                    combos[j][k] = temp;
                }
            }
        }
    }
}
