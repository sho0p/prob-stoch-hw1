/*************************************************************
 *              Written by Zachary Shoop                     *
 *  For Probability and Stochastic Processes                 *
 *  Homework 1 Problem 3                                     *
 *                                                           *
 *  Purpose is to simulate the rolling of three dice rolls   *
 *  for a supplied number of trials and calculate the        *
 *  frequency of each dice occurance, in particular the      *
 *  frequency of dice outcomes 9 and 10.                     *
 *************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

       
int roll_the_dice()
{
    int dice_rolls = 0;
    for ( int i = 0; i < 3; i++ ){
        dice_rolls += ( rand() % 6 + 1);
    }
    return dice_rolls;
}


int main(int argc, char* argv[])
{
    //time seed
    srand((unsigned)time(NULL));
    if ( argc != 2 ){
        printf("Usage: ./three_dice_monty [number of trials]\n");
    }
    int trial_count = atoi(argv[1]);
    /*      set count for all results to be 0     *
     * 15 because the bounds are 3-18 inclusive   */
    int result_count[16] = {0};
    for ( int i = 0; i < trial_count; i++){
        int current_result = roll_the_dice();
        /* -3 since the lower bound is 3 *
         *    normalize it to 0          */
        result_count[current_result-3]++;
    }
    for ( int i =0; i < 16; i++ ){
        float frequency = (float)result_count[i] / (float)trial_count;
        printf ( "Total number of %d results: %d, frequency is %.3f%%\n", \
                                  i+3, result_count[i], frequency*100.);
    }
    return 0;
}
