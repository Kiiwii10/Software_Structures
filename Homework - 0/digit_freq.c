// 123456789
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

enum { MAX_LEN = 1000, NUM_OF_DIGITS = 10 };

/**
 * @brief Count the digit frequency in a given string
 * @param argc Number of arguments
 * @param argv Pointer to arguments
 * @return Non-zero value in case of an error
 */
int main(int argc, char **argv) {
    int input_len, hist[NUM_OF_DIGITS] = {0};
    char input[MAX_LEN];
    scanf("%s", input);
    input_len = strlen(input);
    for (int i = 0; i < input_len; i++){
        int curr_char = input[i] - '0';
        // Count only digits
        if(curr_char >= 0 && curr_char <= NUM_OF_DIGITS - 1){
            hist[curr_char]++;
        }
    }
    for(int i = 0; i < NUM_OF_DIGITS; i++){
        printf("%d", hist[i]);
        if(i < NUM_OF_DIGITS - 1){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
