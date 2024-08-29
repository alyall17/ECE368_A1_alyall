#include <stdio.h>

// Bubble sort algorithm for coin combinations
void bubbleSort(int combos[][4], int numCombos){
    // VARIABLES
    int i; // Outer loop control variable
    int j; // Inner loop control variable
    int k; // Swapping loop control variable
    int temp; // Temporary variable for swapping values

    // EXECUTABLE STATEMENTS
    for(i = 0; i < numCombos - 1; i++){
        for(j = i + 1; j < numCombos; j++){
            // Compare combinations based on quarters, dimes, and nickels
            if(combos[i][0] < combos[j][0] || // More quarters
                (combos[i][0] == combos[j][0] && combos[i][1] < combos[j][1]) || // Same quarters, more dimes
                (combos[i][0] == combos[j][0] && combos[i][1] == combos[j][1] && combos[i][2] < combos[j][2]) || // Same quarters & dimes, more nickels
                (combos[i][0] == combos[j][0] && combos[i][1] == combos[j][1] && combos[i][2] == combos[j][2] && combos[i][3] < combos[j][3])){ // Same quarters, dimes, nickels, more pennies)

                // Swap the combinations
                for(k = 0; k < 4; k++){
                    temp = combos[i][k];
                    combos[i][k] = combos[j][k];
                    combos[j][k] = temp;
                }
            }
        }
    }
}

// Determines and outputs all coin combinations for an integer input
void printCombos(int cents){
    // LOCAL CONSTANTS
    const int QUARTER = 25;
    const int DIME = 10;
    const int NICKEL = 5;
    const int PENNY = 1;

    // ARRAYS AND VARIABLES
    int combos[10000][4]; // Coin combos array
    int numCombos = 0; // Total number of combinations for a specific input
    int q; // Quarters lcv (loop control variable)
    int d; // Dimes lcv
    int n; // Nickels lcv
    int p; // Pennies lcv
    int i; // Printing combos lcv

    // EXECUTABLE STATEMENTS
    // Brute force approach to generating all combos
    for(q = 0; q <= cents / QUARTER; q++){
        for(d = 0; d <= (cents - q * QUARTER) / DIME; d++){
            for(n = 0; (cents - q * QUARTER - d * DIME) / NICKEL; n++){
                p = cents - q * QUARTER - d * DIME - n * NICKEL;
                if(p >= 0){
                    combos[numCombos][0] = q;
                    combos[numCombos][1] = d;
                    combos[numCombos][2] = n;
                    combos[numCombos][3] = p;
                    numCombos++;
                }
            }
        }
    }

    // Sort the combinations using a bubble sort algorithm
    bubbleSort(combos, numCombos);

    // Output all combinations
    for(i = 0; i < numCombos; i++){
        printf("%d quarter(s), %d dime(s), %d nickel(s), %d pennie(s)\n",
                combos[i][0], combos[i][1], combos[i][2], combos[i][3]);
    }

    return(0);
}

int main(){
    // VARIABLES
    int cents; // Inputted cent value

    // EXECUTABLE STATEMENTS
    printf("Enter the number of cents: ");
    scanf("%d", &cents);

    // Print all valid combinations
    printCombos(cents);

    return(0);
}